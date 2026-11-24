int led_pin = 8;
int button_pin = 7;
int led_state = 0;
int last_state = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int current_state = digitalRead(button_pin);
  if (current_state == 1 && last_state == 0) {  // (current_state == 0 && last_state == 1) for falling edge 
    led_state = !led_state;                     // this code is raising edge
  }

  Serial.println(led_state);
  digitalWrite(led_pin, led_state);
  last_state = current_state;
  delay(100);

}
