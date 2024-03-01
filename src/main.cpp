#include "variable.h"
#include "wf.h"
#include "webToken.h"

void setup()
{
  // wifi manager
  setupWifi();
  delay(1000);
  // sertifikat
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  // web
  setupWeb();

  // lcd
  lcd.begin();
  lcd.backlight();
  // servo
  myServo.attach(servoPin);
}

void loop()
{
  if (botKondisi == true)
  {
    if (millis() > lastTimeBotRan + botRequestDelay)
    {
      int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

      while (numNewMessages)
      {
        Serial.println("got response");
        handleNewMessages(numNewMessages);
        numNewMessages = bot.getUpdates(bot.last_message_received + 1);
      }
      lastTimeBotRan = millis();
    }
  }
}