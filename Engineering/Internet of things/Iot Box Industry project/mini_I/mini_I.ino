#include "Config.h"
#include <BlynkSimpleEsp32.h>
#include "Sensor.h"
#include <Wire.h>
#include "oled.h"
#include "Global.h"
#include "Rtc.h"

BlynkTimer timer;
BlynkTimer timer_2;
BlynkTimer timer_3;

bool last_state_1 = 1;
bool last_state_2 = 1;

unsigned long last_pressed_1 = 0;
unsigned long last_pressed_2 = 0;

BLYNK_WRITE(V0) {
  relay_state_1 = param.asInt();
  update_relay_ui();
}

BLYNK_WRITE(V1) {
  relay_state_2 = param.asInt();
  update_relay_ui();
}

BLYNK_CONNECTED() {
  Blynk.virtualWrite(V0, 0);
  Blynk.virtualWrite(V1, 0);
}

void read_sensor_event() {

  int new_temp = read_temperature();
  int new_humid = read_humidity();

  temperature = new_temp;
  humidity = new_humid;

  Serial.print("temp : ");
  Serial.println(temperature);
  Serial.print("Humid : ");
  Serial.println(humidity);

  update_sensor_ui();
  
  Blynk.virtualWrite(V2, temperature);
  Blynk.virtualWrite(V3, humidity);
}



void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, wifi_ssid, wifi_password);
  init_rtc();

  timer.setInterval(10000L, read_sensor_event);
  timer_2.setInterval(1000L, update_time_ui);
  timer_3.setInterval(3600000L, sync_time);

  pinMode(relay_1 , OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);

  Wire.begin(oled_sda, oled_scl);
  
  begin_oled();
  begin_sensor();
  draw_main_screen();
  update_relay_ui();
  
}

void loop() {
  unsigned long current_time = millis();

  bool current_state_1 = digitalRead(button_1);
  if (current_state_1 == 0 && last_state_1 == 1 && current_time - last_pressed_1 >= 100) {
    Serial.println("Button 1 pressed");
    last_pressed_1 = current_time;
    relay_state_1 = !relay_state_1;
    update_relay_ui();
    Blynk.virtualWrite(V0, relay_state_1);
  }

  bool current_state_2 = digitalRead(button_2);
  if (current_state_2 == 0 && last_state_2 == 1 && current_time - last_pressed_2 >= 100) {
    Serial.println("Button 2 pressed");
    last_pressed_2 = current_time;
    relay_state_2 = !relay_state_2;
    update_relay_ui();
    Blynk.virtualWrite(V1, relay_state_2);
  }
  
  last_state_1 = current_state_1;
  last_state_2 = current_state_2;

  digitalWrite(relay_1, relay_state_1);
  digitalWrite(relay_2, relay_state_2);

  Blynk.run();
  timer.run();
  timer_2.run();
  timer_3.run();
}