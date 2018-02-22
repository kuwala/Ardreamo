#ifndef LedSegment2_h
#define LedSegment2_h

class LedSegment2 {
public:
  LedSegment2();
  int getLength();
  void draw();
  void setStart(int start_);

private:
  int length;
  int start;

};

#endif
