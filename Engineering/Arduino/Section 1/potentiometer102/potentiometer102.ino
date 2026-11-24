const int led_pin = 9;
const int poten_pin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(poten_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(poten_pin);
  int out = value / 4;
  Serial.println(out);
  analogWrite(led_pin, out);
  delay(10);
}
