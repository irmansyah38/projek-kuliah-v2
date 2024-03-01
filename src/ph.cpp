#include "ph.h"

PHClass::PHClass(int pin) : phPin(pin), Po(0), PH4(3.3), PH7(2.6)
{
  pinMode(phPin, INPUT);
}

float PHClass::getPhValue()
{
  nilai_analog_PH = analogRead(phPin);

  TeganganPh = 3.3 / 4095.0 * nilai_analog_PH;

  PH_step = (PH4 - PH7) / 3;
  Po = 7.00 + ((PH7 - TeganganPh) / PH_step);

  return Po;
}
