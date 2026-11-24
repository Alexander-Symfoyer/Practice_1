#define BLYNK_PRINT            Serial
#define BLYNK_TEMPLATE_ID     "TMPL6ee6PlLF4"
#define BLYNK_TEMPLATE_NAME   "IOT Course basic"
#define BLYNK_AUTH_TOKEN      "YiuY6JXTcE1pXwfHTuEa8qd-SLa6MGAu"

#include <BlynkSimpleEsp32.h>

BLYNK_WRITE(V1) {
  int value = param.asInt();
  Serial.print("Relay 1 : ");
  Serial.println(value);
  digitalWrite(32, value);
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  Serial.print("Relay 2 : ");
  Serial.println(value);
  digitalWrite(33, value);
}

BLYNK_CONNECTED() {
  Serial.println("Connected");
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);

  Blynk.virtualWrite(V1, 0);
  Blynk.virtualWrite(V2, 0);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "PUNPAY", "0898456212");
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
}

void loop() {
  Blynk.run();
}