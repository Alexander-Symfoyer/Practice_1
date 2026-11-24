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
const unsigned long interval = 500;
bool circle_state = 0;

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
  if (current_time - previous_time >= interval) {
    previous_time = current_time;
    circle_state = !circle_state;
    
    display.clearDisplay();
    if (circle_state) {
      display.fillCircle(64, 32, 15, SSD1306_WHITE);
    }
    display.display();
  }
}
