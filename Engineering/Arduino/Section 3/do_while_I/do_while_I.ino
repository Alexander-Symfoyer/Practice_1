int i = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  do {
    Serial.println(i);
    i++;
    delay(100);
  } while (i < 10);
  
}
