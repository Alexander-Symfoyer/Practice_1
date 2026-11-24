#include "ModbusMaster.h"
#define max485 19 // max485_EN
// EN = enable (1 = transmit, 0 = recieve)

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
  // (baud rate, parity bits, RO, DI)
  // RO = reciever output (RO -> UART RX)
  // DI = driver input (UART TX ->  DI)
  Serial.begin(9600);
  pinMode(max485, OUTPUT);
  digitalWrite(max485, 0);
  
  node.begin(1, Serial1);
  node.preTransmission(pre_transmission);
  node.postTransmission(post_transmission);
}

void loop() {
  // put your main code here, to run repeatedly:
  float result = node.readInputRegisters(1, 2);     
  // 1 = temp, 2 = humid (parameter 1)
  // 1 = read 1 data, 2 = read 2 data (parameter 2)

  if (result == 0) {
    float temp = node.getResponseBuffer(0);
    float humid = node.getResponseBuffer(1);
    Serial.println(temp / 10);
    Serial.println(humid);
  }
  else {
    Serial.println("ERROR");
  }

  delay(1000);  
}
