#include "ModbusMaster.h"
#define max485 19 

ModbusMaster node;

void pre_transmission() {
  digitalWrite(max485, 1);
}

void post_transmission() {
  digitalWrite(max485, 0);
}

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(9600);
  pinMode(max485, OUTPUT);
  digitalWrite(max485, 0);
  
  node.begin(1, Serial1);
  node.preTransmission(pre_transmission);
  node.postTransmission(post_transmission);

  node.writeSingleRegister(0x0101, 2);
  node.writeSingleRegister(0x0102, 19200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
