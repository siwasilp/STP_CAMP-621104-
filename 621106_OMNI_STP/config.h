#include <analogWrite.h>
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#define WifiHidden 0 // 0 = broadcast SSID, 1 = hide SSID
#define WifiMaxCont 2 // maximum simultaneous connected clients (1-4) 
#define WifiChannel 12 // Wi-Fi channel number (1-13)

WebServer server(80);
String RxCommand = "Hello Test"; 
int speedCar = 150, LEDState = 0, delayStep = 500; 

int e_d[4][2] = {

  // { Enable , Disable }
  {23, 21}, //Wheel A (ฝั่งคนขับ)
  {18, 4}, //Wheel B
  {35, 33}   //Wheel D
};
int pin[4][2] = {

  // { RPWM , LPWM }
  {22, 19},   //Wheel A (ฝั่งคนขับ)
  {5, 15},   //Wheel B
  {32, 25}     //Wheel D
};
int acculate = 100;

void HTTP_handleRoot(void) {
 if (server.hasArg("State")) {
 RxCommand = server.arg("State");
 }
 server.send ( 200, "text/html", "" );
}
