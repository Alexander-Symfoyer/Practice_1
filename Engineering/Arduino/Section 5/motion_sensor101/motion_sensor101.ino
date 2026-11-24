#define PIR_PIN 7

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  Serial.println(digitalRead(PIR_PIN));
  delay(1);
}