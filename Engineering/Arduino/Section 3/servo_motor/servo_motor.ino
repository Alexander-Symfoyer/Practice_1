#include <Servo.h>
Servo myservo;

int pulse_width = 1000;
const int motor = 9;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(motor);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int pos = 0; pos <= 180; pos++) {
    myservo.write(pos);
    delay(20);
  }
  for (int pos = 180; pos >= 0; pos--) {
    myservo.write(pos);
    delay(20);
  }
}
