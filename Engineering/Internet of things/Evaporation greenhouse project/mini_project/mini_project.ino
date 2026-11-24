#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define dht_pin 15
#define relay_pump 32
#define relay_fan 33
#define button_1 16
#define button_2 17
#define oled_sda 21
#define oled_scl 22

#define screen_width 128
#define screen_height 64

#define oled_address 0x3c
#define oled_reset -1

Adafruit_SSD1306 display (
  screen_width,
  screen_height,
  &Wire,
  oled_reset
);

DHT dht(dht_pin, DHT22);

const char* ssid = "PUNPAY";
const char* password = "0898456212";

const char* access_token = "fr8PNPxmeTVfcZ3J4xtS";
const char* mqtt_server = "mqtt.thingsboard.cloud";

WiFiClient esp_client;
PubSubClient client(esp_client);

unsigned long last_read = 0;
unsigned long last_publish = 0;

float target_temp = 30;
float target_humid = 60;
bool auto_mode = 0;

int pump_state = 0, fan_state = 0;
int last_fan_state = 0, last_pump_state = 0;
int last_pump_button = 1, last_fan_button = 1;

float temp = NAN;
float humid = NAN;

bool is_target_valid = 0;


void publish_state() {
  JsonDocument doc;
  doc["temperature"] = temp;
  doc["humidity"] = humid;
  doc["pumpState"] = pump_state;
  doc["fanState"] = fan_state;

  char buffer[200];
  serializeJson(doc, buffer);
  Serial.println(buffer);
  client.publish("v1/devices/me/telemetry", buffer);
}


void draw_screen() {

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setTextWrap(false);

  // Header
  display.setCursor(0, 0);
  display.print("Evap GreenHouse");
  display.drawLine(0, 10, 127, 10, SSD1306_WHITE);

  // Sensor
  display.setCursor(0, 13);
  if (isnan(temp)) {
    display.print("Temp: --.- C");
  } else {
    display.printf("Temp: %5.1f C", temp);
  }

  display.setCursor(0, 23);
  if (isnan(humid)) {
    display.print("Humid: --.- %");
  } else {
    display.printf("Humid: %5.1f %%", humid);
  }

  // Relay status
  display.setCursor(0, 35);
  display.printf("Pump: %s", pump_state ? "ON" : "OFF");

  display.setCursor(68, 35);
  display.printf("Fan: %s", fan_state ? "ON" : "OFF");

  // Target
  display.setCursor(0, 45);
  display.printf("Target %0.1fC  %0.1f%%", target_temp, target_humid);

  // Mode
  display.setCursor(0, 55);
  display.printf("Mode: %s", auto_mode ? "AUTO" : "MANUAL");

  display.display();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println(topic);
  Serial.write(payload, length);
  Serial.println(" ");

  JsonDocument doc;
  if (deserializeJson(doc, payload, length)) {
    return;
  }

  String t = topic;
  if (t == "v1/devices/me/attributes") {
    if (!doc["TargetTemperature"].isNull()) {
      target_temp = doc["TargetTemperature"];
    }

    if (!doc["TargetHumidity"].isNull()) {
      target_humid = doc["TargetHumidity"];
    }

    if (!doc["AutoMode"].isNull()) {
      auto_mode = doc["AutoMode"];
    }

    is_target_valid = 1;
  }

  else if (t.startsWith("v1/devices/me/attributes/response/1")) {
    char buffer[200];
    serializeJson(doc, buffer);
    Serial.println(buffer);

    if (!doc["shared"].isNull()) {
      if (!doc["shared"]["TargetTemperature"].isNull()) {
        target_temp = doc["shared"]["TargetTemperature"];
      }
      if (!doc["shared"]["TargetHumidity"].isNull()) {
        target_humid = doc["shared"]["TargetHumidity"];
      }
      if (!doc["shared"]["AutoMode"].isNull()) {
        auto_mode = doc["shared"]["AutoMode"];
      }
      draw_screen();
    }

  }
  
  else if (t.startsWith("v1/devices/me/rpc/request/")) {
    String method = doc["method"].as<String>();
    String id = t.substring(26);
    String resp_topic = "v1/devices/me/rpc/response/" + id;

    // Serial.println(method);
    // Serial.println(id);
    // Serial.println(resp_topic);
    if (method == "setFan" || method == "getFan") {
      if (!auto_mode) {
        fan_state = doc["params"];
        client.publish(resp_topic.c_str(), fan_state == 0 ? "false" : "true");  
      }
    }
    else if (method == "setPump" || method == "getPump") {
      if (!auto_mode) {
        pump_state = doc["params"];
        client.publish(resp_topic.c_str(), pump_state == 0 ? "false" : "true");  
      }
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  dht.begin();
  Wire.begin(oled_sda, oled_scl);

  if (!display.begin(SSD1306_SWITCHCAPVCC, oled_address)) {
    Serial.println("OLED initialization failed!");
    while (true) delay(100);
  }

  pinMode(relay_fan, OUTPUT);
  pinMode(relay_pump, OUTPUT);
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wifi connected!");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  if (client.connect("ESP32", access_token, "")) {
    Serial.println("connected to broker");

    JsonDocument doc;
    doc["firmware_version"] = "1.0.0";
    doc["model"] = "Evap_Greenhouse_Controller";
    doc["ip_address"] = WiFi.localIP().toString();

    char buffer[200];
    serializeJson(doc, buffer);
    client.publish("v1/devices/me/attributes", buffer);
    client.subscribe("v1/devices/me/attributes");
    client.subscribe("v1/devices/me/attributes/response/+");
    client.subscribe("v1/devices/me/rpc/request/+");

    JsonDocument doc2;
    doc2["sharedKeys"] = "TargetTemperature,TargetHumidity,AutoMode";
    char buffer2[200];
    serializeJson(doc2, buffer2);
    client.publish("v1/devices/me/attributes/request/1", buffer2);

  }
  else {
    Serial.println("failed");
  }

  draw_screen();
}


void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - last_read >= 2000) {
    last_read = millis();

    temp = dht.readTemperature();
    humid = dht.readHumidity();

    if (auto_mode) {
      if (is_target_valid) {
        if (temp > target_temp) {
          fan_state = 1;

          if (humid < target_humid) {
            pump_state = 1;
          }
          else {
            pump_state = 0;
          }
        }

      else {
        fan_state = 0;
        pump_state = 0;
      }
    }
  }
  draw_screen();
}
  if (!auto_mode) {
    int pump_button = digitalRead(button_1);
    int fan_button = digitalRead(button_2);

    if (pump_button == 0 && last_pump_button == 1) {
      pump_state = !pump_state;
    }
    if (fan_button == 0 && last_fan_button == 1) {
      fan_state = !fan_state;
    }

    last_pump_button = pump_button;
    last_fan_button = fan_button;

    if (millis() - last_publish >= 5000) {
      last_publish = millis();
      publish_state();
    }
  }

  if (last_fan_state != fan_state || last_pump_state != pump_state) {
    publish_state();
    draw_screen();
  }

  last_fan_state = fan_state;
  last_pump_state = pump_state;

  digitalWrite(relay_fan, !fan_state);
  digitalWrite(relay_pump, !pump_state);

  client.loop();
}
