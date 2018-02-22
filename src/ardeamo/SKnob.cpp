#include "SKnob.h"

SKnob::SKnob(int max) {
  this->max = max;
}
void SKnob::move(int movement) {
  // move knob some get some value
  // make sure knob is in expectd range
  value += movement;

  // value cam be clamped
  // or value can wrap around
  if (value < 0) {
    value = 0;
  }
  if (value > max) {
    value = max;
  }
}
int SKnob::getValue() {
  return value;
}
