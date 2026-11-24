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

unsigned long previous_time = 0;
int progress = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(oled_sda, oled_scl);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, oled_address)) {
    Serial.println("OLED initialization failed!");
    while (true) delay(100);
  }

  display.clearDisplay();
  
 

  display.display();

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current_time = millis();
  if (current_time - previous_time >= 100) {
    previous_time = current_time;
    progress = (progress + 1) % 101;

    int bar_width = map(progress, 0, 100, 0, 104);
    // (value, fromlow, fromhigh, tolow, tohigh)

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 8); 
    display.print("loading : ");
    display.print(progress);
    display.println("%");

    display.drawRect(10, 25, 108, 14, SSD1306_WHITE);
    display.fillRect(12, 27, bar_width, 10, SSD1306_WHITE);

    display.display();

  }
}

