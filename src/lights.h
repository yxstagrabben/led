#ifndef LIGHTS_H
#define LIGHTS_H
#include <Arduino.h>
//void colorWipe(uint32_t color, int wait);
//void theaterChase(uint32_t color, int wait);
void rainbow(int wait);
//void theaterChaseRainbow(int wait);
void initLedLights();
void setBrightness(int brightness);
void ledOFF();
void setColour(	uint32_t c, uint16_t first, uint16_t count);

#endif