#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <LiquidCrystal_I2C.h>

enum UiState {
  HomeScreen,
  MenuScreen,
  SetOnTimeScreen,
  SetOffTimeScreen,
};

extern UiState g_state;
extern int g_relayState;
extern LiquidCrystal_I2C g_lcd;
extern RtcDateTime g_now;

extern long g_on_time[];
extern long g_off_time[];

extern ThreeWire myWire;
extern RtcDS1302<ThreeWire> Rtc;

void refreshScreen();
void loadSchedule();
void saveSchedule();
void bip();

#endif
