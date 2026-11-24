void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("====================");
  Serial.println("ESP32 TEST");
  Serial.println("ESP32 IS WORKING!");
  Serial.println("====================");
}

void loop() {
  Serial.print("Uptime: ");
  Serial.print(millis() / 1000);
  Serial.println(" seconds");

  delay(1000);
}