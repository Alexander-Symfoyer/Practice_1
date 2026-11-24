const int led_pin = 7;
const int button_pin = 6;
int last_button_state = 1;
int blinked = 0;
unsigned long last_time = 0;
int led_state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button_state = digitalRead(button_pin);
  if (button_state == 1 && last_button_state == 0) {
    blinked = !blinked;
  }
  
  if (blinked == 1) {
    unsigned long current_time = millis();
    if (current_time - last_time >= 100) {
      led_state = !led_state;
      last_time = current_time;
    }
  }
  else {
    led_state = 0;
  }

  digitalWrite(led_pin, led_state);

  last_button_state = button_state;
}