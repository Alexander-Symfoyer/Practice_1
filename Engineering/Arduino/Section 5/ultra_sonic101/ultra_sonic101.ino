
#define trig_pin 7
#define echo_pin 8

void setup() {
  Serial.begin(115200);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig_pin, LOW);

  unsigned long duration = pulseIn(echo_pin, HIGH, 30000UL);

  if (duration == 0) {
    Serial.println("Out of range");
  } 
  else {
    float distance = duration / 58.0;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
