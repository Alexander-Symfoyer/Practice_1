#ifndef GLOBAL_H
#define GLOBAL_H

#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

enum Ui_state {
  Home_screen,
  Menu_screen,
  Set_on_screen,
  Set_off_screen,
};

extern long g_on_time[];
extern long g_off_time[];

void load_schedule();
void save_schedule();
void bip();

extern unsigned long last_interact;
extern bool is_sleep;

extern enum Ui_state g_state;
extern int g_relay_state;

extern RtcDateTime g_now;
extern LiquidCrystal_I2C g_lcd;

extern ThreeWire my_wire;
extern RtcDS1302<ThreeWire> Rtc;

extern volatile bool timer1_flag;
void refresh_screen();

#endif