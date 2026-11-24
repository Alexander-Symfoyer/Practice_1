#include <RtcDS1302.h>
#include "time.h"
#include "Global.h"

ThreeWire myWire(26, 25, 27);
RtcDS1302<ThreeWire> Rtc(myWire);

void sync_time() {
  struct tm timeinfo;
  getLocalTime(&timeinfo);

  if (!getLocalTime(&timeinfo)) {
    return;
  }

  RtcDateTime ntp_time(
    timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday, 
    timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec
  );
  Rtc.SetDateTime(ntp_time);
}

void init_rtc() {
  Rtc.Begin();
  configTime(25200, 0, "pool.ntp.org");
  sync_time();
}

void read_from_rtc() {
  now = Rtc.GetDateTime();
}
