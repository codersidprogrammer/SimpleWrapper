#include "ESP8266WiFi.h"

const char *ssid = "HUAWEI";
const char *pass = "123456";
unsigned long _now;
unsigned long _lastTime;
unsigned long _duration;

void callback() {
  Serial.println("Hai Dunia alias Hello World");
}

void setup()
{
  Serial.printf("[WiFi] : Connecting to %s \n", ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.printf("[WiFi] : Connected to %s \n", ssid);
  Serial.print("[WiFi] : IP ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  _now = millis();
  if(_now - _lastTime > _duration)
  {
    _lastTime = _now;
    callback();
  }
}