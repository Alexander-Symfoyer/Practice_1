
#define SOUND_PIN A0

void setup() {
  Serial.begin(115200);
}

void loop() {
  int minValue = 1023;
  int maxValue = 0;

  unsigned long startTime = millis();

  while (millis() - startTime < 50) {
    int value = analogRead(SOUND_PIN);

    if (value < minValue) {
      minValue = value;
    }

    if (value > maxValue) {
      maxValue = value;
    }
  }

  int amplitude = maxValue - minValue;

  Serial.print("Min: ");
  Serial.print(minValue);

  Serial.print(" Max: ");
  Serial.print(maxValue);

  Serial.print(" Amplitude: ");
  Serial.println(amplitude);

  delay(20);
}
