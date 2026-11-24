int ledpin = 8;
int buttonpin = 7;
int ledstate =  0;
int laststate = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int currentstate = digitalRead(buttonpin);
  if (currentstate == 1 && laststate == 0) {
    Serial.println("Button pressed");
    ledstate = !ledstate;
  }
  digitalWrite(ledpin, ledstate);
  laststate = currentstate;
  delay(100);
}
