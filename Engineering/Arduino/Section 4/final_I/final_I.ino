#include "Setup.h"

void timer_isr();

int button_pin[] = {
  button_0, button_1, button_2, button_3
};
bool last_state[] = {0, 0, 0, 0};
unsigned long last_pressed[] = {0, 0, 0, 0};

void setup() {

  Serial.begin(9600);

  load_schedule();


  pinMode(button_0, INPUT);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  pinMode(button_3, INPUT);
  pinMode(relay_out, OUTPUT);
  pinMode(buzzer_out, OUTPUT);

  g_lcd.init();
  g_lcd.backlight();

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timer_isr);

  Rtc.Begin();

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

  g_now = Rtc.GetDateTime();

  if (g_now < compiled) {
    Rtc.SetDateTime(compiled);
  }

  refresh_screen();

}
unsigned long last_interact = 0;


void loop() {

  if (g_state == Home_screen) {
    display_home_screen();
  }
  else if (g_state == Menu_screen) {
    display_menu_screen();
  }
  else {

  }

  for (int i = 0; i < 4; i++) {

    bool current_state = digitalRead(button_pin[i]);

    unsigned long current_time = millis();

    if (current_state == 1 &&
        last_state[i] == 0 &&
        (current_time - last_pressed[i] > 200)) {
        
      bip();
      g_lcd.clear();

      if (is_sleep) {
        is_sleep = 0;
        g_lcd.backlight();
      }
      else {
        if (g_state == Home_screen) {
          button_home_screen(i);
        }
        else if (g_state == Menu_screen) {
          button_menu_screen(i);
        }
        else if (g_state == Set_on_screen || g_state == Set_off_screen) {
          button_set_time_screen(i);
        }

        timer1_flag = true;
        refresh_screen();
        last_pressed[i] = current_time;

        last_interact = current_time;
      }
    }

    last_state[i] = current_state;
  }

  digitalWrite(relay_out, g_relay_state);
  if (is_sleep) {
    g_lcd.noBacklight();
    g_lcd.clear();
  }
}


void timer_isr() {
  timer1_flag = true;
}