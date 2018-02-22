#ifndef SKnob_h
#define SKnob_h

/*
A software Knob. for storying knob positions
*/

class SKnob {
  public:
    SKnob(int max);
    int getValue();
    void move(int movement); // Move knob positive clockwise
  private:
    int value;
    int max;
};

#endif
