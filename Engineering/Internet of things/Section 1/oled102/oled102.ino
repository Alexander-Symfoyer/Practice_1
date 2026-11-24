#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define oled_sda 21
#define oled_scl 22

#define screen_width 128
#define screen_height 64

#define oled_address 0x3c
#define oled_reset -1

Adafruit_SSD1306 display (
  screen_width,
  screen_height,
  &Wire,
  oled_reset
);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(oled_sda, oled_scl);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, oled_address)) {
    Serial.println("OLED initialization failed!");
    while (true) delay(100);
  }

  display.clearDisplay();
  display.drawPixel(64, 32, SSD1306_WHITE);
  display.drawFastHLine(10, 10, 100, SSD1306_WHITE);
  display.drawFastVLine(64, 10, 40, SSD1306_WHITE);
  display.display();

  delay(2000);

  display.clearDisplay();
  display.drawRoundRect(10, 10, 100, 40, 8, SSD1306_WHITE);
  // (x, y, width, height, radius, color)
  display.fillRoundRect(10, 10, 100, 40, 8, SSD1306_WHITE);
  display.display();

  delay(2000);

  display.clearDisplay();
  display.drawTriangle(
    64, 5, 
    10, 55, 
    118, 55, 
    SSD1306_WHITE
  );
  // (x1, y1, x2, y2, x3, y3, color)
  
  display.fillTriangle(
    64, 5, 
    10, 55, 
    118, 55, 
    SSD1306_WHITE
  );
  // (x1, y1, x2, y2, x3, y3, color)
  display.display();

}

void loop() {
  // put your main code here, to run repeatedly:

}
