int last_time = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current_time = millis();
  if (current_time - last_time >= 1000) {
    Serial.println("Hi");
    last_time = current_time;
  }

}
