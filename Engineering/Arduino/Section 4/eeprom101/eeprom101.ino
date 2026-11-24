#include <EEPROM.h>
// 1024 slot 0 - 1023
// each store 1 bytes (8 bits) (0 - 255)


void setup() {
  // put your setup code here, to run once:
  EEPROM.write(0, 52);       // address, uint_8t
  int x = EEPROM.read(0);
  Serial.begin(9600);
  Serial.println(x);

  long y = 1000;      // 1 - 4
  EEPROM.put(1, y);   
  EEPROM.get(1, y);
  Serial.println(y);
}

void loop() {
  // put your main code here, to run repeatedly:

}
