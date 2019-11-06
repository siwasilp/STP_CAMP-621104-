#include "config.h"

const char* Wifi_Name = "STP_M";
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
    if (RxCommand == "R")rr();
    if (RxCommand == "F")fw();
    if (RxCommand == "B")rw();
    if (RxCommand == "G")fwl();
    if (RxCommand == "I")fwr();
    if (RxCommand == "H")rwl();
    if (RxCommand == "J")rwr();
    if (RxCommand == "W")rt360();
    if (RxCommand == "w")lt360();
    if (RxCommand == "S")stp();   
  }
  delay(50);
}
