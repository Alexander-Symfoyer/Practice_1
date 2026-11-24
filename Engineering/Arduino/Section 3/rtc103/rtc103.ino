#include <RtcDS1302.h>

ThreeWire myWire(4, 5, 2);
// DAT CLK RST
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  // put your setup code here, to run once:
  Rtc.Begin();
  RtcDatetime now = RtcGetDateTime();
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

  if (compiled < now) {
    Serial.println("RTC time is okay");
  }
  else {
    Serial.println("RTC time is not okay");
    Rtc.SetDateTime(compiled); 
  }
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  RtcDateTime now = Rtc.GetDateTime();
  Serial.print(now.Day());
  Serial.print("/");
  Serial.print(now.Month());
  Serial.print("/");
  Serial.print(now.Year());
  Serial.print(" ");

  Serial.print(now.Hour());
  Serial.print(":");
  Serial.print(now.Minute());
  Serial.print(":");
  Serial.println(now.Second());
  delay(1000);
}
