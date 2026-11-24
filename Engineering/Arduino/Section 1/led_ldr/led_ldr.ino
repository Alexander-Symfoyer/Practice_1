int ldr_pin = A0;
int led_pin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(ldr_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(ldr_pin);
  if (value >= 250) {
    digitalWrite(led_pin, LOW);
  }
  else if (value <= 220) {
    digitalWrite(led_pin, HIGH);
  }
  Serial.println(value);
  delay(100);
}
