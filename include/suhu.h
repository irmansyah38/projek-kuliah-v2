#ifndef SUHU_H
#define SUHU_H

#include <OneWire.h>
#include <DallasTemperature.h>

class SuhuClass
{
private:
  int suhuPin;
  OneWire oneWire;
  DallasTemperature sensors;

public:
  SuhuClass(int pin); // Corrected constructor name
  float getSuhuValue();
};

#endif
