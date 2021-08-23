#include <SimpleWrapper.h>

const char* ssid = "HUAWEI";
const char* pass = "123456";

SimpleWrapper simple;

void callback() {
  Serial.println("Hai Dunia alias Hello World");
}

void setup() {
  simple.begin(ssid, pass);
  simple.setInterval(3000, callback);
}

void loop() {
  simple.handle();
}