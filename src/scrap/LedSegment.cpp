#include "LedSegment.h"
#include "Arduino.h"
#include "FastLED.h"

LedSegment::LedSegment(CRGB* leds_, int numLeds_) {
  leds = leds_;
  numLeds = numLeds_;
  hue = 0;
  length = 1;
  start = 0;

}
void LedSegment::setHue(int hue) {
  hue = hue;
}
void LedSegment::setLength(int length_) {
  length = length_;
}
void LedSegment::draw() {
  for (int i = 0; i < length; i++) {
    // this objects leds pointer
    // use to set the CRGB array to
    leds[i]= CHSV(hue, 255, 127) ;
  }
}
