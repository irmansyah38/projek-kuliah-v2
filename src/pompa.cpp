#include "pompa.h"

PompaClass::PompaClass(int pin) : pompaPin(pin)
{
  pinMode(pompaPin, OUTPUT);
}

void PompaClass::pompaOn()
{
  digitalWrite(pompaPin, HIGH);
}

void PompaClass::pompaOff()
{
  digitalWrite(pompaPin, HIGH);
}