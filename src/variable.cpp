#include "variable.h"

// telegram
WiFiClientSecure client;
UniversalTelegramBot bot("your token", client);
String chatID;

// kondisi bot sudah connect atau belum
bool botKondisi = false;

// servo
Servo myServo;
int servoPin = 13;

// suhu
SuhuClass suhu(25);
float suhuValue;

// ph
PHClass ph(26);
float phValue;

// lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

// menhandle boot
void handleNewMessages(int numNewMessages)
{
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i = 0; i < numNewMessages; i++)
  {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != chatID)
    {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }

    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start")
    {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use the following commands to control your outputs.\n\n";
      welcome += "/led_on to turn GPIO ON \n";
      welcome += "/led_off to turn GPIO OFF \n";
      welcome += "/state to request current GPIO state \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/beri_makan")
    {

      myServo.write(90);
      delay(2000);
      myServo.write(0);
      bot.sendMessage(chat_id, "sudah diberi pakan", "");
    }

    if (text == "/led_off")
    {
      bot.sendMessage(chat_id, "LED state set to OFF", "");
    }
    if (text == "/info_akuarium")
    {

      String info = "suhu akuarium saat ini adalah : " + String(suhu.getSuhuValue());
      delay(1000);
      bot.sendMessage(chat_id, info, "");
    }
  }
}

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;
