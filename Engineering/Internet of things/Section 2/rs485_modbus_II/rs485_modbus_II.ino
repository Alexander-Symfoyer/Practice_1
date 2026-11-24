#define max485 19

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, 16, 17);
  pinMode(max485, OUTPUT);
  digitalWrite(max485, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0) {
    char incoming_byte = Serial1.read();
    Serial.print(incoming_byte);
  }
}
