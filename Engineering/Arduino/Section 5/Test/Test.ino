#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  delay(100);

  Serial.println("RC522 Test");
  rfid.PCD_DumpVersionToSerial();
}

void loop() {
  if (rfid.PICC_IsNewCardPresent() &&
      rfid.PICC_ReadCardSerial()) {

    Serial.println("CARD DETECTED!");

    rfid.PICC_DumpToSerial(&(rfid.uid));

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}