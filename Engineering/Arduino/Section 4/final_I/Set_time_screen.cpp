#include "Setup.h"

int slot_index = 0;
int is_editing = 0;
int editing_time[] = {0, 0, 0};   // hour, minute, second
int editing_index = 0;

void display_set_time_screen() {

  g_lcd.setCursor(0, 0);
  if (g_state == Set_on_screen) {
    g_lcd.print("On");
  }
  else {
    g_lcd.print("Off");
  }

  g_lcd.setCursor(7, 0);
  g_lcd.print("1");

  g_lcd.setCursor(9, 0);
  g_lcd.print("2");

  g_lcd.setCursor(11, 0);
  g_lcd.print("3");

  g_lcd.setCursor(13, 0);
  g_lcd.print("4");

  g_lcd.setCursor(15, 0);
  g_lcd.print("5");

  if (is_editing) {
    char time[16];
    sprintf(time, "%02u:%02u:%02u", editing_time[0], editing_time[1], editing_time[2]);
    g_lcd.setCursor(8, 1);
    g_lcd.print(time);
  }
  else {
    long current_time;
    if (g_state == Set_on_screen) {
      current_time = g_on_time[slot_index];
    }
    else {
      current_time = g_off_time[slot_index];
    }
    if (current_time < 0) {
      g_lcd.setCursor(9, 1);
      g_lcd.print("NO DATA");
    }
    else {
      int hour = current_time / 3600;
      int minute = (current_time / 60) % 60;
      int second = current_time % 60;

      char time[16];
      sprintf(time, "%02u:%02u:%02u", hour, minute, second);
      g_lcd.setCursor(8, 1);
      g_lcd.print(time);
    }
  }

  if (is_editing) {
    if (editing_index == 0) {
      g_lcd.setCursor(15, 1);
    }
    else if (editing_index == 1) {
      g_lcd.setCursor(14, 1);
    }
    else if (editing_index == 2) {
      g_lcd.setCursor(12, 1);
    }
    else if (editing_index == 3) {
      g_lcd.setCursor(11, 1);
    }
    else if (editing_index == 4) {
      g_lcd.setCursor(9, 1);
    }
    else if (editing_index == 5) {
      g_lcd.setCursor(8, 1);
    }
  }
  else {
    g_lcd.setCursor(slot_index * 2 + 7, 0);
    g_lcd.blink();
  }

}

void increment(int &value, int max_value, int digit) {
  int current_digit = (value / digit) % 10;
  if (current_digit >= max_value) {
    value = value - (max_value * digit);
  }
  else {
    value += digit;
  }
}

void decrement(int &value, int max_value, int digit) {
  int current_digit = (value / digit) % 10;
  if (current_digit == 0) {
    value += (max_value * digit);
  }
  else {
    value -= digit;
  }
}

void button_set_time_screen(int index) {

  if (index == 1) {

    if (is_editing) {

      if (editing_index == 0) {
        increment(editing_time[2], 9, 1);
      }

      else if (editing_index == 1) {
        increment(editing_time[2], 5, 10);
      }

      else if (editing_index == 2) {
        increment(editing_time[1], 9, 1);
      }

      else if (editing_index == 3) {
        increment(editing_time[1], 5, 10);
      }

      else if (editing_index == 4) {
        increment(editing_time[0], 9, 1);
      }

      else if (editing_index == 5) {
        if (editing_time[0] % 10 > 3) {
          increment(editing_time[0], 1, 10);
        }
        else {
          increment(editing_time[0], 2, 10);
        }
      } 
    }
    else {
      slot_index = (slot_index - 1 + 5) % 5;
    }
  }
  else if (index == 0) {
    if (is_editing) {
      if (editing_index == 0) {
        decrement(editing_time[2], 9, 1);
      }

      else if (editing_index == 1) {
        decrement(editing_time[2], 5, 10);
      }

      else if (editing_index == 2) {
        decrement(editing_time[1], 9, 1);
      }

      else if (editing_index == 3) {
       decrement(editing_time[1], 5, 10);
      }

      else if (editing_index == 4) {
        decrement(editing_time[0], 9, 1);
      }

      else if (editing_index == 5) {
        if (editing_time[0] % 10 > 3) {
          decrement(editing_time[0], 1, 10);
        }
        else {
          decrement(editing_time[0], 2, 10);
        }
      }
    }
    else {
      slot_index = (slot_index + 1) % 5;
    }
  }
  else if (index == 2) {
    if (is_editing) {
      is_editing = 0;
    }
    else {
      g_state = Menu_screen;
      slot_index = 0;
      g_lcd.noBlink();
    }
  }
  else {
    if (!is_editing) {

      unsigned long start_time_stamp =  millis();
      unsigned long last_time_stamp = 0;
      bool is_long_pressed = 0;

      g_lcd.clear();
      g_lcd.noBlink();

      while (digitalRead(button_3) == 1) {
        unsigned long current_time_stamp = millis();

        if (current_time_stamp - start_time_stamp > 300) {
          g_lcd.setCursor(0, 0);
          g_lcd.print("Deleting...");
          g_lcd.setCursor(0, 1);
          g_lcd.print("[");
          g_lcd.setCursor(15, 1);
          g_lcd.print("]");

          int cursor_pos = (current_time_stamp - (start_time_stamp + 300)) / (2000 / 14);
          g_lcd.setCursor(cursor_pos + 1, 1);
          g_lcd.print("=");
        }

        if (current_time_stamp - start_time_stamp >= 2300) {
          is_long_pressed = 1;
          break;
        }

        last_time_stamp = current_time_stamp;
      }

      g_lcd.clear();
      g_lcd.blink();

      if (is_long_pressed) {
        if (g_state == Set_on_screen) {
          g_on_time[slot_index] = -1;
        }
        else {
          g_off_time[slot_index] = -1;
        }
      }

      if (last_time_stamp - start_time_stamp < 300) {
        is_editing = 1;
        editing_index = 0;
        long now_time;

        if (g_state == Set_on_screen) {
          now_time = g_on_time[slot_index];
        }
        else {
          now_time = g_off_time[slot_index];
        }

        if (now_time < 0) {
          editing_time[0] = 0;
          editing_time[1] = 0;
          editing_time[2] = 0;
        }
        else {
          editing_time[0] = now_time / 3600;
          editing_time[1] = (now_time / 60) % 60;
          editing_time[2] = now_time % 60;
      }
    }

    }
    else {
      editing_index++;
      if (editing_index == 6) {
        is_editing = 0;

        if (g_state == Set_on_screen) {
          g_on_time[slot_index] = (long)editing_time[0] * 3600 + (long)editing_time[1] * 60 + (long)editing_time[2];
        }
        else {
          g_off_time[slot_index] = (long)editing_time[0] * 3600 + (long)editing_time[1] * 60 + (long)editing_time[2];
        }

        slot_index = (slot_index + 1) % 5;
      }
    }
  }

}

