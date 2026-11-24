#include <TimerOne.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize(1000000);   // microseconds
  Timer1.attachInterrupt(timer_isr);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("ACTIVE!");
  delay(100);
}

void timer_isr() {
  Serial.println("INTERRUPTED!");
}
