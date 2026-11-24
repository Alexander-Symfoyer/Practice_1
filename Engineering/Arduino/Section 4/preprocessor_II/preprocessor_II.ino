#define high_speed 1

void setup() {
  // put your setup code here, to run once:

  #if high_speed == 1
  Serial.begin(115200);

  #else
  Serial.begin(9600);

  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("hello");
  delay(500);
}
