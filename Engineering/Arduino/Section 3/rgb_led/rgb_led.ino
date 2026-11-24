int red = 9;
int green = 10;
int blue = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}

void loop() {
  // put your main code here, to run repeatedly:

}
