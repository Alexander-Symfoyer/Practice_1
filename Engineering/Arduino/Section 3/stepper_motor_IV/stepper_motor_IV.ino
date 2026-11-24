#include <Stepper.h>

const int stepsPerRevolution = 2038;

Stepper my_stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  my_stepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Clockwise");
  my_stepper.step(stepsPerRevolution);
  delay(100);

  Serial.println("CounterClockwise");
  my_stepper.step(-stepsPerRevolution);
  delay(100);
}
