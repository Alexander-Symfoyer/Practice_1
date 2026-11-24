const int red_led = 10;
const int yellow_led = 9;
const int green_led = 8;
const int blue_button = 7;
const int yellow_button = 6;

int count = 0;
int last_blue = 0;
int last_yellow = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_button, INPUT);
  pinMode(yellow_button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int current_blue = digitalRead(blue_button);
  int current_yellow = digitalRead(yellow_button);

  if (last_blue == 0 && current_blue == 1) {
    count++;
  }
  if (last_yellow == 0 && current_yellow == 1) {
    count--;
  }

  count = constrain(count, 0, 3);

  digitalWrite(red_led, count >= 1 ? HIGH : LOW);
  digitalWrite(yellow_led, count >= 2 ? HIGH : LOW);
  digitalWrite(green_led, count >= 3 ? HIGH : LOW);

  Serial.println(count);

  last_blue = current_blue;
  last_yellow = current_yellow;

  delay(50);

}
