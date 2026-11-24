#include <Arduino.h>
#include "Global.h"

void btnHomeScreen(int buttonIndex) {
  (void)buttonIndex;
  g_state = MenuScreen;
}

void displayHomeScreen() {
  char datestring[16];

  snprintf(
    datestring,
    sizeof(datestring),
    "%02u/%02u/%04u",
    (unsigned int)g_now.Day(),
    (unsigned int)g_now.Month(),
    (unsigned int)g_now.Year()
  );

  g_lcd.setCursor(0, 0);
  g_lcd.print(datestring);

  char timestring[12];

  snprintf(
    timestring,
    sizeof(timestring),
    "%02u:%02u:%02u",
    (unsigned int)g_now.Hour(),
    (unsigned int)g_now.Minute(),
    (unsigned int)g_now.Second()
  );

  g_lcd.setCursor(0, 1);
  g_lcd.print(timestring);

  g_lcd.setCursor(12, 0);
  g_lcd.print("PUMP");

  if (g_relayState == 1) {
    g_lcd.setCursor(13, 1);
    g_lcd.print(" ON");
  } else {
    g_lcd.setCursor(13, 1);
    g_lcd.print("OFF");
  }
}
