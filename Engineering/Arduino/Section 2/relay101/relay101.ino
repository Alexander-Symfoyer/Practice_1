const int relay_pin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay_pin, HIGH);
  delay(1000);
  digitalWrite(relay_pin, LOW);
  delay(1000);
}
