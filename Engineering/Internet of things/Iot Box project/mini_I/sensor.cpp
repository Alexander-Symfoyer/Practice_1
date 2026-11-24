#include <DHT.h>
#include "Config.h"

DHT dht(dht_pin, DHT22);

void begin_sensor() {
  dht.begin();
}

int read_humidity() {
  return (int)dht.readHumidity();
}

int read_temperature() {
  return (int)dht.readTemperature();
}