#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();

  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("BACKLIGHT ON");
  lcd.setCursor(1,1);
  lcd.print("Hello Zerobike");

}

void loop() {
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("BACKLIGHT ON");
  lcd.setCursor(1,1);
  lcd.print("Hello Zerobike");
}