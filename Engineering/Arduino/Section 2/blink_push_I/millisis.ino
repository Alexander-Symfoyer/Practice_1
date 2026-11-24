const int ledpin = 7;
const int buttonpin = 6;
int lastbuttonstate = 1;
int blinked = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonstate = digitalRead(buttonpin);
  if (buttonstate == 1 && lastbuttonstate == 0) {
    blinked = !blinked;
  }

  Serial.println(blinked);
  
  if (blinked == 1) {
    digitalWrite(ledpin, HIGH);
    delay(100);
    digitalWrite(ledpin, LOW);
    delay(100);
  }
  else {
    digitalWrite(ledpin, LOW);
  }

  lastbuttonstate = buttonstate;
}
