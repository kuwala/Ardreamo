#include "LedSegment2.h"

LedSegment2::LedSegment2 () {
  length = 42;
  start = 0;
}

int LedSegment2::getLength() {
  return length;
}

void LedSegment2::draw() {

}
void LedSegment2::setStart(int start_) {
  start = start_;
}
