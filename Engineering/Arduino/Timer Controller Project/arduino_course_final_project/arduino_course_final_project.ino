#include <Arduino.h>
#include <Wire.h>
#include <RtcDS1302.h>
#include <TimerOne.h>

#include "Global.h"
#include "Pins.h"

#include "HomeScreen.h"
#include "MenuScreen.h"
#include "SetTimeScreen.h"

volatile bool timer1Flag = false;

int buttonPins[] = { BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3 };
bool lastButtonStates[] = { LOW, LOW, LOW, LOW };
unsigned long lastButtonPressed[] = { 0, 0, 0, 0 };
bool isSleep = false;
unsigned long lastInteract = 0;

bool lcdBacklightIsOn = false;

void timerISR();

void updateLcdBacklight() {
  const bool shouldBeOn = !isSleep;

  if (shouldBeOn == lcdBacklightIsOn) {
    return;
  }

  if (shouldBeOn) {
    g_lcd.backlight();
  } else {
    g_lcd.noBacklight();
  }

  lcdBacklightIsOn = shouldBeOn;
}

void applyRelayOutput() {
#if RELAY_ACTIVE_LOW
  // The program's logical state is 1 = ON, 0 = OFF.
  // Invert only the physical output for an active-LOW relay module.
  digitalWrite(RELAY_OUT, g_relayState ? LOW : HIGH);
#else
  // Active-HIGH relay module.
  digitalWrite(RELAY_OUT, g_relayState ? HIGH : LOW);
#endif
}

void setup() {
  Serial.begin(9600);

  loadSchedule();

  // Initialize the DS1302 RTC using the Makuna Rtc library.
  Rtc.Begin();

  if (Rtc.GetIsWriteProtected()) {
    Rtc.SetIsWriteProtected(false);
  }

  if (!Rtc.GetIsRunning()) {
    Rtc.SetIsRunning(true);
  }

  // Set the compile time only when the RTC reports invalid date/time.
  // Do not overwrite the RTC time on every Arduino restart.
  if (!Rtc.IsDateTimeValid()) {
    const RtcDateTime compiled(__DATE__, __TIME__);
    Rtc.SetDateTime(compiled);
  }

  g_now = Rtc.GetDateTime();

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timerISR);

  // Buttons are ACTIVE-HIGH. Use external pull-down resistors.
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT);
  }

  pinMode(RELAY_OUT, OUTPUT);
  pinMode(BUZZER_OUT, OUTPUT);
  digitalWrite(BUZZER_OUT, LOW);

  // Ensure the relay starts in its OFF state.
  g_relayState = 0;
  applyRelayOutput();

  // Initialize the I2C LCD (16 columns x 2 rows).
  g_lcd.init();
  updateLcdBacklight();

  lastInteract = millis();
  refreshScreen();
}

void loop() {
  if (timer1Flag) {
    g_now = Rtc.GetDateTime();

    if (g_state == HomeScreen) {
      refreshScreen();
    }

    const long currentSod = (long)g_now.Hour() * 3600L
                          + (long)g_now.Minute() * 60L
                          + (long)g_now.Second();

    for (int i = 0; i < 5; i++) {
      if (currentSod == g_on_time[i]) {
        g_relayState = 1;
        break;
      }
    }

    for (int i = 0; i < 5; i++) {
      if (currentSod == g_off_time[i]) {
        g_relayState = 0;
        break;
      }
    }

    if (millis() - lastInteract >= 5000UL) {
      isSleep = true;
    }

    timer1Flag = false;
  }

  for (int i = 0; i < 4; i++) {
    const int currentButtonState = digitalRead(buttonPins[i]);
    const unsigned long currentTime = millis();

    // Active-HIGH button: LOW -> HIGH means pressed.
    if (currentButtonState == HIGH &&
        lastButtonStates[i] == LOW &&
        currentTime - lastButtonPressed[i] > 200UL) {

      bip();

      if (isSleep) {
        // The first press only wakes the LCD.
        isSleep = false;
      } else {
        g_lcd.clear();

        if (g_state == HomeScreen) {
          btnHomeScreen(i);
        } else if (g_state == MenuScreen) {
          btnMenuScreen(i);
        } else if (g_state == SetOnTimeScreen ||
                   g_state == SetOffTimeScreen) {
          btnSetTimeScreen(i);
        }

        refreshScreen();
        lastButtonPressed[i] = currentTime;
      }

      lastInteract = currentTime;
    }

    lastButtonStates[i] = currentButtonState;
  }

  applyRelayOutput();
  updateLcdBacklight();
}

void timerISR() {
  timer1Flag = true;
}
