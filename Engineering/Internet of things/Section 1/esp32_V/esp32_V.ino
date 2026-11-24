#define BLYNK_PRINT            Serial
#define BLYNK_TEMPLATE_ID     "TMPL6ee6PlLF4"
#define BLYNK_TEMPLATE_NAME   "IOT Course basic"
#define BLYNK_AUTH_TOKEN      "YiuY6JXTcE1pXwfHTuEa8qd-SLa6MGAu"

#include <BlynkSimpleEsp32.h>

BlynkTimer timer;
int temperature = 0;

void my_timer() {
  temperature++;
  Blynk.virtualWrite(V0, temperature);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "PUNPAY", "0898456212");
  timer.setInterval(600000L, my_timer);
}

void loop() {
  Blynk.run();
  timer.run();
}