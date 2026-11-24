#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 5  // Configurable, see typical pin layout above
#define SS_PIN 53  // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

MFRC522::MIFARE_Key key;

byte en_key[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Initialize serial communications with the PC
  SPI.begin();         // Init SPI bus
  mfrc522.PCD_Init();  // Init MFRC522 card
  for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {
    key.keyByte[i] = en_key[i];
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    readData(&key, 7);
    // writeData(&key, 7);

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}


void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void readData(MFRC522::MIFARE_Key *key, byte block) {
  bool result = false;
  byte buffer[18];
  MFRC522::StatusCode status;
  byte byteCount = sizeof(buffer);
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, key, &(mfrc522.uid));
  status = mfrc522.MIFARE_Read(block, buffer, &byteCount);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Read() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
  } else {
    // Successful read
    Serial.print(F("Success with key:"));
    dump_byte_array(key->keyByte, MFRC522::MF_KEY_SIZE);
    Serial.println();
    Serial.print(F("Block "));
    Serial.print(block);
    Serial.print(F(":"));
    dump_byte_array(buffer, 16);
    Serial.println();
  }
}
void writeData(MFRC522::MIFARE_Key *key, byte block) {
  MFRC522::StatusCode status;
  byte dataBlock[] = {
    0x01, 0x02, 0x03, 0x04,  
    0x05, 0x06, 0xFF, 0x07,  
    0x80, 0x69, 0xFF, 0xFF,  
    0xFF, 0xFF, 0xFF, 0xFF   
  };

  // byte dataBlock[] = {
  //   0x00, 0x01, 0x02, 0x03,  //  0,  1,   2,  3,
  //   0x04, 0x05, 0x06, 0x07,  //  4,  5,   6,  7,
  //   0x08, 0x09, 0x0A, 0x0B,  //  8, 9, 10, 11,
  //   0x0C, 0x0D, 0x0E, 0x0F   // 12, 13, 14, 15
  // };
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, key, &(mfrc522.uid));
  status = (MFRC522::StatusCode)mfrc522.MIFARE_Write(block, dataBlock, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
  } else {
    Serial.print(F("Success with key:"));
    dump_byte_array(key->keyByte, MFRC522::MF_KEY_SIZE);
    Serial.println();
    Serial.print(F("Block "));
    Serial.print(block);
    Serial.print(F(":"));
    dump_byte_array(dataBlock, 16);
    Serial.println();
  }
}