void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = digitalRead(7);
  Serial.println(x);
  delay(1000);
}
