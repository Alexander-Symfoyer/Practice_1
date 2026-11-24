const int poten_pin = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(poten_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(poten_pin);
  Serial.println(value);
  delay(100);
}
