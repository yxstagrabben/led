#include <Arduino.h>
#include <WiFi.h>
#include <Adafruit_NeoPixel.h>

#include <wifiConnect.h>
#include <lights.h>

#define ssid "TinaTeens"
#define passwd "Fenja2010"

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    
   ;
    
  }

  connect(ssid, passwd);

  initLedLights();
  setBrightness(100);
}

void loop() {
  wifiRequest();
  delay(10);
}