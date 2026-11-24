#include <WiFi.h>
#include <PubSubClient.h>

int i = 0;
const char* ssid = "PUNPAY";
const char* password = "0898456212";

const char* access_token = "fr8PNPxmeTVfcZ3J4xtS";

const char* mqtt_server = "mqtt.thingsboard.cloud";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, 1883);

  if (client.connect("ESP32_Device",access_token,"")) {
    Serial.println("connected");
  } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  char data[10];
  sprintf(data, "{\"i\":%d}", i);

  client.publish("v1/devices/me/telemetry",data);
  client.loop();
  i++;
  delay(1000);
}