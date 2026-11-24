#include "Setup.h"
#include <stdio.h>

void button_home_screen(int index) {

  g_state = Menu_screen;

}

void display_home_screen() {

  if (timer1_flag) {

    g_now = Rtc.GetDateTime();

    g_lcd.setCursor(0, 0);

    char date[11];

    snprintf(date, sizeof(date), "%02u/%02u/%04u",
             (unsigned int)g_now.Day(),
             (unsigned int)g_now.Month(),
             (unsigned int)g_now.Year());

    g_lcd.print(date);

    g_lcd.setCursor(0, 1);

    char time[9];

    snprintf(time, sizeof(time), "%02u:%02u:%02u",
             (unsigned int)g_now.Hour(),
             (unsigned int)g_now.Minute(),
             (unsigned int)g_now.Second());

    g_lcd.print(time);

    g_lcd.setCursor(12, 0);
    g_lcd.print("Pump");

    g_lcd.setCursor(12, 1);
    if (g_relay_state == 0) {
      g_lcd.print("  On"); 
    }
    else {
      g_lcd.print(" Off");
    }

    long current_sod = (long)g_now.Hour() * 3600 + (long)g_now.Minute() * 60 + (long)g_now.Second();

    for (int i = 0; i < 5; i++) {
      if (current_sod == g_on_time[i]) {
        g_relay_state = 0;
        break;
      }
    }

    for (int i = 0; i < 5; i++) {
      if (current_sod == g_off_time[i]) {
        g_relay_state = 1;
        break;
      }
    }

    if (millis() - last_interact >= 5000) {
      is_sleep = 1;
    }

    timer1_flag = false;
  }

}