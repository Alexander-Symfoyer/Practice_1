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

int temp_data[6] = {
  25, 29, 32, 37, 24, 21
};

void draw_graph() {

  // draw axis
  display.drawLine(10, 10, 10, 55, SSD1306_WHITE);
  display.drawLine(10, 55, 120, 55, SSD1306_WHITE);

  for (int i = 0; i < 5; i++) {
    int x1 = 10 + (i * 20);
    int x2 = 10 + ((i + 1) * 20);

    int y1 = map(temp_data[i], 20, 40, 50, 10);
    int y2 = map(temp_data[i+1], 20, 40, 50, 10);
    // value, fromlow, fromhigh, tolow, tohigh

    display.drawLine(x1, y1, x2, y2, SSD1306_WHITE);
    display.fillCircle(x1, y1, 2, SSD1306_WHITE);
  }
  display.fillCircle(110, map(temp_data[5], 20, 40, 50, 10), 2, SSD1306_WHITE);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(oled_sda, oled_scl);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, oled_address)) {
    Serial.println("OLED initialization failed!");
    while (true) delay(100);
  }

  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println("Temperature Graph");

  draw_graph();

  display.display();

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current_time = millis();
  
}

