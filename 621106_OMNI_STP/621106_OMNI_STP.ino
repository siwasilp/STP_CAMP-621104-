#include "config.h"

const char* Wifi_Name = "STP_X";
const char* Wifi_Pass = "123456789";

void setup() {
  Serial.begin(115200);
  init();
}

void loop() {
  server.handleClient();
  if (RxCommand != "Hello Test") {
    LEDState = 1 - LEDState;
    digitalWrite(LED_BUILTIN, LEDState);
    Serial.println(RxCommand);

    if (RxCommand == "L")ll();
    if (RxCommand == "R")rrr();
    if (RxCommand == "F")fw();
    if (RxCommand == "B")rw();
    if (RxCommand == "G")fwr();
    if (RxCommand == "I")fwl();
    if (RxCommand == "H")rwr();
    if (RxCommand == "J")rwl();
    if (RxCommand == "S")stp();
  }
  delay(50);
}
