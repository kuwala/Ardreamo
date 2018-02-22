#define LedSegment_h
#ifndef LedSegment_h
#include "Arduino.h"
#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 13

class LedSegment {
  public:
    LedSegment(CRGB *leds, int numLeds);
    void update();
    void begin();
    void setLength(int length);
    void setStart(int start);
  private:
    CRGB* leds;
    uint8_t hue;
    int numLeds;
    int length;
    int start;
};

#endif
