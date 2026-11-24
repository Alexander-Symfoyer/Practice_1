int ledpin = 9;
int brightness = 0;
int direction = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (brightness >= 255) {
    direction = -1;
  }
  if (brightness <= 0) {
    direction = 1;
  }

  analogWrite(ledpin, brightness);
  Serial.println(brightness);
  brightness += direction;
  delay(100);

}
