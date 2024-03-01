#include <wf.h>

void setupWifi()
{
  WiFiManager wm;

  WiFi.mode(WIFI_STA);

  Serial.begin(115200);

  bool res;

  res = wm.autoConnect("irmansyah123", "irmansyah123");

  if (!res)
  {
    Serial.println("gagal terhubung");
  }
  else
  {
    Serial.println("Terhubung koneksi wifi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  }
}
