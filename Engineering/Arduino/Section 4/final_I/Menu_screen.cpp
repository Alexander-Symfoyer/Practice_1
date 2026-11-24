#include "Setup.h"
#include <stdio.h>

// index 0 = left
// index 1 = right
// index 2 = cancel
// index 3 = okay

char menu[3][20] = {"SET ON TIME", "SET OF TIME", "   MANUAL   "};
unsigned int menu_index = 0;

void button_menu_screen(int index) {

  if (index == 0) {
    menu_index = (menu_index - 1 + 3) % 3;
  }
  else if (index == 1) {
    menu_index = (menu_index + 1) % 3;
  }
  else if (index == 2) {
    g_state = Home_screen;
    timer1_flag = true;
  }
  else {
    if (menu_index == 0) {
      g_state = Set_on_screen;
    }
    else if (menu_index == 1) {
      g_state = Set_off_screen;
    }
    else {
      g_relay_state = !g_relay_state;
    }
  }

}

void display_menu_screen() {

  g_lcd.setCursor(0, 0);
  g_lcd.print('<');

  g_lcd.setCursor(15, 0);
  g_lcd.print('>');

  g_lcd.setCursor(2, 0);
  g_lcd.print(menu[menu_index]);

}