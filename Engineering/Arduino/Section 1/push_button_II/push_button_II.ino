int led_pin = 8;
int button_pin = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(button_pin);
  digitalWrite(led_pin, !value);
  Serial.println(value);
  delay(500);
}
