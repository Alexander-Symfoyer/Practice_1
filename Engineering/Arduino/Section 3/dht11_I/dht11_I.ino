#include "DHT.h";
DHT dht(7, DHT11);


void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double humidity = dht.readHumidity();
  double temp = dht.readTemperature();
  delay(500);
  Serial.print("H : ");
  Serial.println(humidity);
  Serial.print("T : ");
  Serial.println(temp);
}
