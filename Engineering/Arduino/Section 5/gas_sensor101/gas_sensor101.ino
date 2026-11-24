#define gas_pin A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(gas_pin);
  Serial.print("MQ-2 value : ");
  Serial.println(value);
  
  delay(500);
}
