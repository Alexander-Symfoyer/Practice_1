#include <WiFi.h>

const char *ssid = "PUNPAY";
const char *password = "0898456212";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address : ");
  Serial.println(WiFi.localIP());

  configTime(25200, 0, "pool.ntp.org");
  // (gmtOffset_sec, daylightOffset_sec, ntpServer)
}

void loop() {
  // put your main code here, to run repeatedly:
  struct tm timeinfo;
  getLocalTime(&timeinfo);
  
  char time[30];
  sprintf(time, "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  Serial.println(time);

  char date[30];
  sprintf(date, "%02d/%02d/%04d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900);
  // (month 0-11, year since 1900)
  Serial.println(date);

  

  delay(1000);
}
