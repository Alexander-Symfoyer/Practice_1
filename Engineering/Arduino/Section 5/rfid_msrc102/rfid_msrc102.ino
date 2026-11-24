#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 5

MFRC522 rfid(SS_PIN, RST_PIN);
byte myCard[4] = {0x6B, 0xCF, 0xD8, 0x53};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
 
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    int is_mycard = 1;

    for (int i = 0; i < 4; i++) {
      Serial.print(rfid.uid.uidByte[i], HEX);
      Serial.print(" ");
      if (rfid.uid.uidByte[i] != myCard[i]) {
        is_mycard = 0;
      }
    }

    Serial.println(" ");

    if (is_mycard == 1) {
      Serial.println("This is my card");
    }
    else {
      Serial.println("This is not my card");
    }
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

}