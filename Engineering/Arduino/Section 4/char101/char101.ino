char x[] = {'h', 'e', 'l', 'l', 'o', '\0'};
char y[] = {'h', 'e', 'l', 'l', '\0', 'o'};
char z[] = "hello";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
}

void loop() {
  // put your main code here, to run repeatedly:

}
