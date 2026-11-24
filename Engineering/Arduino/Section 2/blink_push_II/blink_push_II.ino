int ledpin = 7;
unsigned long last_time = 0;
int led_state = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned current_time = millis();
  if (current_time - last_time >= 1000) {
    led_state = !led_state;
    last_time = current_time;
  }
  digitalWrite(ledpin, led_state);
}
