#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Image.h"
#include "Global.h"
#include "Rtc.h"

#define oled_sda 21
#define oled_scl 22

#define screen_width 128
#define screen_height 64
 
#define oled_address 0x3c
#define oled_reset -1

Adafruit_SSD1306 display (
  screen_width,
  screen_height,
  &Wire,
  oled_reset
);

void begin_oled() {
  Wire.begin(oled_sda, oled_scl);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, oled_address)) {
    Serial.println("OLED initialization failed!");
    while (true) delay(100);
  }
}


void draw_main_screen() {
  display.clearDisplay();

  display.drawBitmap(108, 1, logos, 17, 17, SSD1306_WHITE);
  display.drawBitmap(5, 25, temperature_icons, 14, 16, SSD1306_WHITE);
  display.drawBitmap(5, 45, humidity_icons, 14, 15, SSD1306_WHITE);

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(4, 2);
  display.print("20/11/2026");

  display.setCursor(4, 12);
  display.print("21:19:45");

  display.display();
}

void update_sensor_ui() {
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(25, 28);
  display.print(temperature);

  display.setCursor(25, 48);
  display.print(humidity);

  display.display();
}

void update_relay_ui() {
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.fillRect(72, 28, 50, 8, SSD1306_BLACK);
  display.setCursor(72, 28);
  display.print("R1: ");
  display.print(relay_state_1 ? "OFF" : "ON");

  display.fillRect(72, 48, 50, 8, SSD1306_BLACK);
  display.setCursor(72, 48);
  display.print("R2: ");
  display.print(relay_state_2 ? "OFF" : "ON");

  display.display();
}

void update_time_ui() {
  read_from_rtc();

  char date[30];
  sprintf(date, "%02u/%02u/%04u", now.Day(), now.Month(), now.Year());
  display.setCursor(4, 2);
  display.fillRect(4, 2, 65, 8, SSD1306_BLACK);
  display.print(date);

  char time[30];
  sprintf(time, "%02u:%02u:%02u", now.Hour(), now.Minute(), now.Second());
  display.setCursor(4, 12);
  display.fillRect(4, 12, 50, 8, SSD1306_BLACK);
  display.print(time);

  display.display();
}