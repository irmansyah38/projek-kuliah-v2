// Telegram.h
#ifndef VARIABLE_H
#define VARIABLE_H

#include <Arduino.h>
#include "UniversalTelegramBot.h"
#include "WiFiClientSecure.h"
#include <ESP32Servo.h>
#include "suhu.h"
#include <LiquidCrystal_I2C.h>
#include "ph.h"

// tele bot
extern WiFiClientSecure client;
extern UniversalTelegramBot bot;
extern String chatID;
extern bool botKondisi;

// servo
extern Servo myServo;
extern int servoPin;

// suhu
extern SuhuClass suhu;
extern float suhuValue;

// ph
extern PHClass ph;
extern float phValue;

// lcd
extern LiquidCrystal_I2C lcd;

// html webtoken
extern const char index_html[] PROGMEM;

// handle boot
void handleNewMessages(int numNewMessages);

// Checks for new messages every 1 second.
extern int botRequestDelay;
extern unsigned long lastTimeBotRan;

#endif