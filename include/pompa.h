#ifndef POMPA_H
#define POMPA_H

#include <Arduino.h>

class PompaClass
{
private:
  int pompaPin;

public:
  PompaClass(int pin);
  void pompaOn();
  void pompaOff();
};

#endif