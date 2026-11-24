void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  char c[10] = "Hello";
  // Hello\0rzyc
  // "Hello" = Hello + \0 (6 char now)
  // \0 = null terminator

  Serial.println(c);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:

}
