#include "LedSegment2.h"
#include <Arduino.h>

LedSegment2::LedSegment2 (CRGB* leds_, int num_leds_) {
  leds = leds_;
  num_leds = num_leds_;
  length = 1;
  start = 0;
  hue = 0;
  brightness = 0;
}

int LedSegment2::getLength() {
  return length;
}

void LedSegment2::draw() {
  for (int i = start; i < (start+length); i++) {
    // this objects leds pointer
    // use to set the CRGB array to
    leds[i]= CHSV(random(255), 255, brightness) ;
    // leds[i]= CHSV(hue, 255, 127) ;
  }
}
void LedSegment2::setBrightness(uint8_t brightness_) {
  if(brightness_ >= 0 && brightness_ < 256) {
    brightness = brightness_;
  }
}
void LedSegment2::setStart(int start_) {
  if(start_ >= 0 && start_ < num_leds - length) {
    start = start_;
  } else {
    Serial.print("LedSegment Start Position out of bounds (ignored): ");
    Serial.println(start_);
  }
}
