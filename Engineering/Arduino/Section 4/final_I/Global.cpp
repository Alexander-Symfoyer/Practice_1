#include "Global.h"
#include "Pin.h"
#include "Home_screen.h"
#include "Menu_screen.h"
#include "Set_time_screen.h"

enum Ui_state g_state = Home_screen;
int g_relay_state = 1;
RtcDateTime g_now;

long g_on_time[] = {-1, -1, -1, -1, -1,};
long g_off_time[] = {-1, -1, -1, -1, -1};

void save_schedule() {

  int address = 0;
  for (int i = 0; i < 5; i++) {
    EEPROM.put(address, g_on_time[i]);
    address += 4;   // long use 4 bytes (32 bit)
                    // or sizeof(long)
  }

  for (int i = 0; i < 5; i++) {
    EEPROM.put(address, g_off_time[i]);
    address += 4; 
  }

}

void load_schedule() {

  int magic_number = EEPROM.read(255);
  if (magic_number != 100) {
    save_schedule();
    EEPROM.write(255, 100);
  }
  int address = 0;
  for (int i = 0; i < 5; i++) {
    EEPROM.get(address, g_on_time[i]);
    address += 4;
  }

  for (int i = 0; i < 5; i++) {
    EEPROM.get(address, g_off_time[i]);
    address += 4;
  }

}

void bip() {
  digitalWrite(buzzer_out, HIGH);
  delay(50);
  digitalWrite(buzzer_out, LOW);
}

unsigned long last_interact = 0;
bool is_sleep = 0;

LiquidCrystal_I2C g_lcd(0x27, 16, 2);

ThreeWire my_wire(rtc_dat, rtc_clk, rtc_rst);
RtcDS1302<ThreeWire> Rtc(my_wire);

volatile bool timer1_flag = false;

void refresh_screen() {

  if (g_state == Home_screen) {
    display_home_screen();
  }
  else if (g_state == Menu_screen) {
    display_menu_screen();
  }
  else if (g_state == Set_on_screen || g_state == Set_off_screen) {
    display_set_time_screen();
  }

}