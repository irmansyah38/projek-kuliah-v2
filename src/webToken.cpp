#include "webToken.h"

const char index_html[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang="en">

<head>
  <title>Aquascape</title>
  <!-- Required meta tags -->
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />

  <!-- Bootstrap CSS v5.2.1 -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet"
    integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous" />
</head>

<body>

  <main class="container">
    <div class="w-75 mx-auto">
      <form action="/token" method="post">
        <div class="mb-3">
          <label for="token" class="form-label">Bot</label>
          <input type="text" class="form-control" name="token" id="token" aria-describedby="helpId" placeholder="" />
          <input type="text" class="form-control" name="chatid" id="chatid" aria-describedby="helpId" placeholder="" />
        </div>
        <button type="submit" class="btn btn-primary">
          Submit
        </button>
      </form>
    </div>
  </main>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.min.js"
    integrity="sha384-BBtl+eGJRgqQAUMxJ7pMwbEyER4l1g+O15P+16Ep7Q9Q+zqX6gSbd85u4mG4QzX+"
    crossorigin="anonymous"></script>
</body>

</html>
)rawliteral";

AsyncWebServer server(8080);

void handleTokenSubmit(AsyncWebServerRequest *request)
{
  String tokenValue, chatid;
  bool validInput = false;

  while (!validInput)
  {
    if (request->hasParam("token", true) && request->hasParam("chatid", true))
    {
      tokenValue = request->getParam("token", true)->value();
      chatid = request->getParam("chatid", true)->value();
      validInput = true;
    }
    else
    {
      request->send(400, "text/plain", "Invalid request, please fill in the input fields");
      delay(1000); // delay 1 second before retrying
    }
  }

  // Lakukan sesuatu dengan nilai token, misalnya menyimpannya atau mengirimkannya ke BotFather
  bot.updateToken(tokenValue);
  while (bot.getMe() == false)
  {
    Serial.println("token masih salah tolong isi kembali");
  }
  chatID = chatid;
  request->send(200, "text/plain", "Token received: " + bot.getToken() + " " + chatID);
  bot.sendMessage(chatID, "good luck you are conecting", "");
  botKondisi = true;
  server.end();
}

void setupWeb()
{
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/html", index_html); });

  server.on("/token", HTTP_POST, handleTokenSubmit);

  server.begin();
}