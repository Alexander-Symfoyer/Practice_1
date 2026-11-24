void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int x = 10;
  int y = 10;
  unsigned long z = x * y;
  double a = 100;
  double b = 10;
  double c = a / b;
  int d = x % y;
  Serial.println(z);
  Serial.println(c);
  Serial.println(d);
}

void loop() {
  // put your main code here, to run repeatedly:

}
