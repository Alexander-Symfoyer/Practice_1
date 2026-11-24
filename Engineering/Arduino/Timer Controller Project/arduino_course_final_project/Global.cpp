#include <Arduino.h>
#include <EEPROM.h>

#include "Pins.h"
#include "HomeScreen.h"
#include "MenuScreen.h"
#include "SetTimeScreen.h"
#include "Global.h"

UiState g_state = HomeScreen;
int g_relayState = 0;  // Logical state: 0 = OFF, 1 = ON.

LiquidCrystal_I2C g_lcd(
  LCD_I2C_ADDRESS,
  LCD_COLUMNS,
  LCD_ROWS
);

RtcDateTime g_now;

// ThreeWire expects (DAT, CLK, RST), not (CLK, DAT, RST).
ThreeWire myWire(RTC_DAT, RTC_CLK, RTC_RST);
RtcDS1302<ThreeWire> Rtc(myWire);

long g_on_time[] = { -1, -1, -1, -1, -1 };
long g_off_time[] = { -1, -1, -1, -1, -1 };

void bip() {
  digitalWrite(BUZZER_OUT, HIGH);
  delay(50);
  digitalWrite(BUZZER_OUT, LOW);
}

void loadSchedule() {
  const int magicNumber = EEPROM.read(77);

  if (magicNumber != 99) {
    saveSchedule();
    EEPROM.write(77, 99);
  }

  int address = 0;

  for (int i = 0; i < 5; i++) {
    EEPROM.get(address, g_on_time[i]);
    address += sizeof(long);
  }

  for (int i = 0; i < 5; i++) {
    EEPROM.get(address, g_off_time[i]);
    address += sizeof(long);
  }
}

void saveSchedule() {
  int address = 0;

  for (int i = 0; i < 5; i++) {
    EEPROM.put(address, g_on_time[i]);
    address += sizeof(long);
  }

  for (int i = 0; i < 5; i++) {
    EEPROM.put(address, g_off_time[i]);
    address += sizeof(long);
  }
}

void refreshScreen() {
  if (g_state == HomeScreen) {
    displayHomeScreen();
  } else if (g_state == MenuScreen) {
    displayMenuScreen();
  } else if (g_state == SetOnTimeScreen ||
             g_state == SetOffTimeScreen) {
    displaySetTimeScreen();
  }
}
