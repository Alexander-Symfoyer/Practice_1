#ifndef PINS_H
#define PINS_H

// Arduino Uno R3: I2C LCD
// SDA = A4, SCL = A5
#define LCD_I2C_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// DS1302 RTC via Makuna ThreeWire.
// ThreeWire constructor order is DAT, CLK, RST.
#define RTC_CLK 12
#define RTC_DAT 11
#define RTC_RST 10

// Output pins
#define RELAY_OUT 9
#define BUZZER_OUT A3

// Buttons are ACTIVE-HIGH.
// Each input requires an external pull-down resistor (for example 10k ohm).
// The button connects the input pin to 5V when pressed.
#define BUTTON_0 7  // Left
#define BUTTON_1 6  // Right
#define BUTTON_2 5  // Cancel
#define BUTTON_3 4  // OK

// Hardware-specific relay polarity.
// 1 = active-LOW relay module, 0 = active-HIGH relay module.
// The program's logical state remains: g_relayState 1 = ON, 0 = OFF.
// This default follows the active-LOW relay behavior in your earlier code.
#define RELAY_ACTIVE_LOW 1

#endif
