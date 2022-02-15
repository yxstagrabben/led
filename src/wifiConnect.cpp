#include <Arduino.h>
#include <wifiConnect.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <lights.h>

 


AsyncWebServer server(80);

void connect(const char *ssid,const  char* passwd) {
    WiFi.begin(ssid, passwd);
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }
    
    Serial.println(WiFi.localIP());

}

void wifiRequest(){

    server.on("/led/off", HTTP_GET   , [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "ok");
        ledOFF();
    });
    server.on("/led/red", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain","ok");
        setColour((255, 0, 0), 0, 0);
    });
    
    server.on("/led/green", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain","ok");
        setColour((0, 255, 0), 0, 0);
    });

    server.on("/led/blue", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain","ok");
        setColour((0, 0, 255), 0, 0);
    });

    server.on("/led/rainbow", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain","ok");
        rainbow(50);
    });
    
    server.begin();
}


