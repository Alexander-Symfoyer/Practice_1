#include <DHT.h>

#define DHT_PIN 15
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.println("DHT22 Test Started");
  delay(2000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor reading failed!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }

  delay(2500);
}