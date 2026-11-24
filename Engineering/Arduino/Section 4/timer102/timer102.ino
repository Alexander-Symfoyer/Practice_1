#define button_pin 2

// active low
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button_pin), ext_isr, FALLING);
  // can use RISING and CHANGE and LOW

}

void loop() {
  // put your main code here, to run repeatedly:

}

void ext_isr() {
  Serial.println("EXT!");
}
