int ledpin = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledpin, 10);     // 0-255

}
