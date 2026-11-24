#include "ModbusMaster.h"
#include "Config.h"

ModbusMaster node;

void pre_transmission() {
  digitalWrite(max485_en, 1);
}

void post_transmission() {
  digitalWrite(max485_en, 0);
}

void begin_sensor() {
  Serial1.begin(9600, SERIAL_8N1, max485_ro, max485_di);
  pinMode(max485_en, OUTPUT);
  digitalWrite(max485_en, 0);

  node.begin(1, Serial1);
  node.preTransmission(pre_transmission);
  node.postTransmission(post_transmission);
}

int read_humidity() {
  float result = node.readInputRegisters(2, 1);     

  if (result == 0) {
    float humid = node.getResponseBuffer(0);
    Serial.println(humid);
    return (int)humid;
  }
  else {
    Serial.println("ERROR");
    return 0;
  }

}

int read_temperature() {
  float result = node.readInputRegisters(1, 1);     

  if (result == 0) {
    float temp = node.getResponseBuffer(0);
    Serial.println(temp / 10);
    return (int)(temp / 10);
  }
  else {
    Serial.println("ERROR");
    return 0;
  }
}