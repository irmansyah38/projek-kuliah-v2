#ifndef PH_H
#define PH_H

#include <Arduino.h>
class PHClass
{
private:
  int phPin;
  float Po;
  float PH_step;
  int nilai_analog_PH;
  double TeganganPh;

  // untuk kalibrasi
  float PH4;
  // nilai PH7
  float PH7;

public:
  PHClass(int pin);
  float getPhValue();
};

#endif
