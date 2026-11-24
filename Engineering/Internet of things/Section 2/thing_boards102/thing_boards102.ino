#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ArduinoJson.h>

#define dht_pin 15
#define relay_1_pin 32
#define relay_2_pin 33

DHT dht(dht_pin, DHT22);

const char* ssid = "PUNPAY";
const char* password = "0898456212";

const char* access_token = "fr8PNPxmeTVfcZ3J4xtS";
const char* mqtt_server = "mqtt.thingsboard.cloud";

WiFiClient esp_client;
PubSubClient client(esp_client);

void callback(char* topic, byte* payload, unsigned int length) {
  char data[100];
  strncpy(data, (char*)payload, length);    // string copy
  data[length] = '\0';

  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, data);
  if (error) {
    Serial.print("deserialize Json failed : ");
    Serial.println(error.f_str());
    return;
  }

  const char* method = doc["method"];
  Serial.println(method);

  if (strcmp(method, "turnOn1") == 0) {   // string compare
    digitalWrite(relay_1_pin, LOW);
  }   
  else if (strcmp(method, "turnOff1") == 0) {
    digitalWrite(relay_1_pin, HIGH);
  }
  else if (strcmp(method, "turnOn2") == 0) {
    digitalWrite(relay_2_pin, LOW);
  }
  else if (strcmp(method, "turnOff2") == 0) {
    digitalWrite(relay_2_pin, HIGH);
  }
}

void setup() {
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  dht.begin();
  Serial.begin(115200);

  pinMode(relay_1_pin, OUTPUT);
  pinMode(relay_2_pin, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wifi connected!");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  if (client.connect("ESP32_101", access_token, "")) {
    Serial.println("connected to broker");
    client.subscribe("v1/devices/me/rpc/request/+");
  }
  else {
    Serial.println("failed");
  }
}

void loop() {
  // float temp = dht.readTemperature();
  // float humid = dht.readHumidity();

  // char data[100];
  // sprintf(data, "{\"temperature\":%.1f, \"humidity\":%.1f}", temp, humid);
  // client.publish("v1/devices/me/telemetry", data);
  // Serial.println(data);
  
  client.loop();
}
