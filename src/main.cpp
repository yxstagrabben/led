#include <Arduino.h>
#include <WiFi.h>
#include <Adafruit_NeoPixel.h>

#include <wifiConnect.h>
#include <lights.h>

#define ssid "SSID"
#define passwd "PASSWORD"

void setup() {
  Serial.begin(9600);

  connect(ssid, passwd);

  initLedLights();
  setBrightness(100);
}

void loop() {
  wifiRequest();
  delay(10);
}
