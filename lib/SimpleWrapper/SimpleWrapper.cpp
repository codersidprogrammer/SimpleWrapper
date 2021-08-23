#include "SimpleWrapper.h"

//Constructor
SimpleWrapper::SimpleWrapper(){
  _lastTime = 0;
}

//Memulai semua urusan koneksi ESP8266
void SimpleWrapper::begin(const char* ssid, const char* password) {
    Serial.begin(9600);
    Serial.printf("[WiFi] : Connecting to %s \n", ssid);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (!isWifiConnected())
    {
      delay(500);
      Serial.print(".");
    }
    Serial.printf("[WiFi] : Connected to %s \n", ssid);
    Serial.print("[WiFi] : IP ");
    Serial.println(WiFi.localIP());
}

boolean SimpleWrapper::isWifiConnected() {
  return WiFi.status() == WL_CONNECTED;
}

void SimpleWrapper::setInterval(unsigned long duration, intervalCallback _func){
  _duration = duration;
  _functionCall = _func;
}

void SimpleWrapper::handle() {
  _now = millis();
  if(_now - _lastTime > _duration)
  {
    _lastTime = _now;
    _functionCall();
  }
}