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
    while (true) {
      delay(100);
    }
  }

  Serial.println("OLED initialized successfully!");

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hello, OLED!");
  display.display();

  delay(2000);
  display.clearDisplay();

  display.drawLine(0, 0, 127, 63, SSD1306_WHITE);
  // (x1, y1, x2, y2, color)
  display.drawRect(10, 10, 10, 10, SSD1306_WHITE);
  // (x, y, width, height, color)
  display.fillRect(20, 20, 10, 10, SSD1306_WHITE);

  display.drawCircle(30, 30, 5, SSD1306_WHITE);
  display.fillCircle(40, 40, 5, SSD1306_WHITE);

  display.display();

}

void loop() {
  // put your main code here, to run repeatedly:

}
