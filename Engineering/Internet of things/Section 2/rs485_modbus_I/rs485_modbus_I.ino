#define max485 19
long i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(9600);
  pinMode(max485, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(max485, 1);
  delay(100);
  Serial.println("Sending data...");
  Serial.print("Hello : ");
  Serial.println(i);
  delay(100);
  digitalWrite(max485, 0);
}
