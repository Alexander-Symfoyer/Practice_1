#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define dht_pin 15
#define dht_type DHT22
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

DHT dht(dht_pin, dht_type);

float temperature;
float humidity;

unsigned long previous_time = 0;
const unsigned long interval = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(oled_sda, oled_scl);
  dht.begin();
  
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
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("DHT22 reading failed!");

      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.println("DHT22 Error!");
      display.display();

      return;
    }

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("Temperature : ");
    display.print(temperature);
    display.println(" C");

    display.setCursor(0, 20);
    display.print("Humidity : ");
    display.print(humidity);
    display.println(" %");

    display.display();

  }

}

