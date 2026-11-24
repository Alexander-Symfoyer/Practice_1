int x = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("x = ");
  Serial.println(x % 5);
  x++;
  delay(1000);
}
