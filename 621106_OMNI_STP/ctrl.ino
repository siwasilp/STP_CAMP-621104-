
// เดินหน้า
void fw() {
  analogWrite(pin[0][1], 255);
  analogWrite(pin[0][0], 255 - acculate);
  analogWrite(pin[1][0], 255);
  analogWrite(pin[1][1], 255 - acculate);

  analogWrite(pin[2][1], 255);
  analogWrite(pin[2][0], 255);
  delay(50);
 
}

// ถอยหลัง
void rw() {
  analogWrite(pin[0][0], 255);
  analogWrite(pin[0][1], 255 - acculate);
  analogWrite(pin[1][1], 255);
  analogWrite(pin[1][0], 255 - acculate);

  analogWrite(pin[2][1], 255);
  analogWrite(pin[2][0], 255);
  delay(50);
 
}

// สไลด์ขวา
void rr() {
  analogWrite(pin[0][1], 255);
  analogWrite(pin[0][0], 255 - acculate);
  analogWrite(pin[1][1], 255);
  analogWrite(pin[1][0], 255 - acculate);

  analogWrite(pin[2][1], 255);
  analogWrite(pin[2][0], 255);
  delay(50);
 
}

// สไลด์ซ้าย
void ll() {
  analogWrite(pin[0][0], 255);
  analogWrite(pin[0][1], 255 - acculate);
  analogWrite(pin[1][0], 255);
  analogWrite(pin[1][1], 255 - acculate);

  analogWrite(pin[2][1], 255);
  analogWrite(pin[2][0], 255);
  delay(50);
 
}

// เลี้ยวขวา
void rrr() {
  analogWrite(pin[0][1], 255);
  analogWrite(pin[0][0], 255 - acculate);
  analogWrite(pin[1][1], 255);
  analogWrite(pin[1][0], 255 - acculate);
  analogWrite(pin[2][1], 255);
  analogWrite(pin[2][0], 255 - acculate);
  delay(50);
 

}

// เลี้ยวซ้าย
void lll() {
  analogWrite(pin[0][0], 255);
  analogWrite(pin[0][1], 255 - acculate);
  analogWrite(pin[1][0], 255);
  analogWrite(pin[1][1], 255 - acculate);
  analogWrite(pin[2][0], 255);
  analogWrite(pin[2][1], 255 - acculate);
  delay(50);
 
}


// เดินหน้า 45 องศาฝั่งขวา
void fwr() {
  analogWrite(pin[0][1], 255);
  analogWrite(pin[0][0], 255 - acculate);
  analogWrite(pin[1][0], 255);
  analogWrite(pin[1][1], 255);
  analogWrite(pin[2][0], 255);
  analogWrite(pin[2][1], 255 - acculate);
  delay(50);
 
}

// เดินหน้า 45 องศาฝั่งซ้าย
void fwl() {
  analogWrite(pin[0][1], 255);
  analogWrite(pin[0][0], 255);
  analogWrite(pin[1][0], 255);
  analogWrite(pin[1][1], 255 - acculate);
  analogWrite(pin[2][1], 255);
  analogWrite(pin[2][0], 255 - acculate);
  delay(50);
 
}

// ถอยหลัง 45 องศาฝั่งขวา
void rwr() {
  analogWrite(pin[0][0], 255);
  analogWrite(pin[0][1], 255 - acculate);
  analogWrite(pin[1][0], 255);
  analogWrite(pin[1][1], 255);
  analogWrite(pin[2][1], 255);
  analogWrite(pin[2][0], 255 - acculate);
  delay(50);
 
}

// ถอยหลัง 45 องศาฝั่งซ้าย
void rwl() {
  analogWrite(pin[0][1], 255);
  analogWrite(pin[0][0], 255);
  analogWrite(pin[1][1], 255);
  analogWrite(pin[1][0], 255 - acculate);
  analogWrite(pin[2][0], 255);
  analogWrite(pin[2][1], 255 - acculate);
  delay(50);
 
}

// หยุดรถ
void stp() {
  analogWrite(pin[0][1], 255);
  analogWrite(pin[0][0], 255);
  analogWrite(pin[1][0], 255);
  analogWrite(pin[1][1], 255);
  analogWrite(pin[2][0], 255);
  analogWrite(pin[2][1], 255);
}

//======================================

void Initial_WifiAP_Mode() {
  // Create WiFi AP-Mode
  Serial.print("\n------------------\n");
  Serial.print("1/2: Setup AP-Mode\n");
  Serial.print("Wifi_Name = "); Serial.println(Wifi_Name);
  Serial.print("Wifi_Pass = "); Serial.println(Wifi_Pass);
  Serial.print("Wifi_Channel = "); Serial.println(WifiChannel);
  Serial.print("Setting soft-AP initialize ... ");
  WiFi.mode(WIFI_AP);
  Serial.println(WiFi.softAP(Wifi_Name, Wifi_Pass, WifiChannel, WifiHidden, WifiMaxCont) ?
                 "Ready" : "Failed!");
  // Starting WEB-server
  Serial.print("\n------------------\n");
  Serial.print("2/2: Start server\n");
  server.on ( "/", HTTP_handleRoot );
  server.onNotFound ( HTTP_handleRoot );
  server.begin();
}

// initial pin setup
void init() {
    pinMode(LED_BUILTIN, OUTPUT);
  Initial_WifiAP_Mode();
  for (int i = 0; i < 4; i++) {
    pinMode(e_d[i][0], OUTPUT);
    pinMode(e_d[i][1], OUTPUT);
    digitalWrite(e_d[i][0], HIGH);
    digitalWrite(e_d[i][1], LOW);
  }

  for (int i = 0; i < 4; i++) {
    for (int x : pin[i])
      pinMode(x, OUTPUT);
  }
}
