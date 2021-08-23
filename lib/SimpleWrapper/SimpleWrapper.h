/**
 * 
 *  Library ini dikhususkan untuk merapihkan kode
 *  untuk menghandle konektivitas WiFi di ESP8266
 * */

#ifndef SimpleWrapper_h
#define SimpleWrapper_h

#ifdef ESP8266
#include <core_version.h>
#endif

#include "ESP8266WiFi.h"

//Tipe data buatan yang berisi fungsi bernilai void
typedef void (*intervalCallback)(void);

class SimpleWrapper
{

private:
  //Khusus untuk handling interval
  intervalCallback _functionCall;
  unsigned long _now;
  unsigned long _lastTime;
  unsigned long _duration;

public:
  //Constructor
  SimpleWrapper();

  //Memulai semua urusan koneksi ESP8266
  void begin(const char *ssid, const char *password);

  //Interval handler untuk setiap fungsi yang akan digunakan
  void setInterval(unsigned long duration, intervalCallback _func);

  //Menghandle loop untuk si interval
  void handle();

  // Memberikan status koneksi
  boolean isWifiConnected();
};

#endif