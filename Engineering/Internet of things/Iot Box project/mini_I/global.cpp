#include "Sensor.h"
#include <RtcDS1302.h>

int temperature = read_temperature();
int humidity = read_humidity();

bool relay_state_1 = 0;
bool relay_state_2 = 0;

RtcDateTime now;