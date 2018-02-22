#ifndef LedSegment2_h
#define LedSegment2_h

#include <FastLED.h>

class LedSegment2 {
public:
  LedSegment2(CRGB* leds_, int thing);
  int getLength();
  void draw();
  void setStart(int start_);

private:
  CRGB* leds;
  int num_leds;
  int length;
  int start;
  uint8_t hue;

};

#endif
