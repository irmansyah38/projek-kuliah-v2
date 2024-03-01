#include "suhu.h"

SuhuClass::SuhuClass(int pin) : suhuPin(pin), oneWire(pin), sensors(&oneWire)
{
}

float SuhuClass::getSuhuValue()
{

  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  if (temperature == DEVICE_DISCONNECTED_C)
  {
    // Melempar exception atau nilai yang lebih bersifat spesifik
    Serial.println("Sensor tidak terdeteksi atau mengalami kesalahan. Periksa koneksi atau sensor.");
  }

  return temperature;
}
