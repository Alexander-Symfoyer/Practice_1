#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
// lcd(I2C address, columns, rows);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);      // setCursor(column, row);
  lcd.print("Count : ");      
  lcd.setCursor(8, 0);
  lcd.print(millis() / 1000);
}