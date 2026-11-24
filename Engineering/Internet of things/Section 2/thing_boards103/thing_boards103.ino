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

bool relay_1_state = 1;

WiFiClient esp_client;
PubSubClient client(esp_client);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println(topic);
  char* request_id = strrchr(topic, '/');   // string reverse character
  request_id++;

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
  // Serial.println(method);

  if (strcmp(method, "getState") == 0) {   
    char response_topic[100];
    sprintf(response_topic, "v1/devices/me/rpc/response/%s", request_id);
    Serial.println(response_topic);
    if (relay_1_state == 0) {
      client.publish(response_topic, "true");
    }
    else {
      client.publish(response_topic, "false");
    }
  }
  
}

void setup() {
  // put your setup code here, to run once:

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
  // delay(500);
  
  client.loop();
  digitalWrite(relay_1_pin, relay_1_state);
}
