// Ardeamo v2 Teensy 3.2 Code
// by Daniel Smolentsev
// started 2-14-18

// Libraries
#include <Encoder.h>
#include <Bounce.h>
#include <FastLED.h>

// Custome Class Includes
#include "Sknob.h"
#include "Inputs.h"
#include "SKnob.h"
#include "SanityCheck.h"
// #include "LedSegment.h"
#include "LedSegment2.h"

// Midi
const int channel = 1;
// Joystick Timer
unsigned long timer = 0;
int maxTime = 5;

int mode = 0; // 0 - monkey mode // 1 - gamepad mode
int check = 0;

// Keyboard and Mouse
char c = 'a';

// Mouse
int radius = 5;
float angle = 0;
bool mouseAutoMover = 0;
int mouseXTileMax = 3;
int mouseXTile = 0;
int mouseYTile = 0;
int mousePositions[3][3][2] = {
  {{0, 0}, {600, 0}, {600, 0}},
  {{0, 300}, {300, 300}, {600, 300}},
  {{0, 600}, {300, 600}, {600, 600}}
};

// LED Parts
#define NUM_LEDS 8
// 6?
#define DATA_PIN 13

CRGB leds[NUM_LEDS];
// LedSegment segment1 = LedSegment(leds, NUM_LEDS);
LedSegment2 segment1 = LedSegment2();

int softwareKnob = 0;
int softwareKnobMax = 127;

// Hardware Inputs
Inputs inputs = Inputs();
// Software Inputs
SKnob knob1 = SKnob(127);

void setup() {
  // Set up LedS
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
void mapKnobToLeds() {
  // Map knob rotation to segment start position
  int segment_pos = map(knob1.getValue(), 0, 127, 0, 16);
  segment1.setStart(segment_pos);

}
void loop() {
  // Get Inputs
  inputs.update();
  // Update Objects
  mapKnobToLeds();
  // Draw to Displays
  segment1.draw();
  // Outputs
  FastLED.show();
  delay(30);
}

void modeLogic() {

  /*
  if (mode == 1) {

    if (button1.fallingEdge()) {
      c = random(255);
      Keyboard.print(c);
    }
    if (button2.read() == LOW) {
      Keyboard.print(c);
    }

    if (button3.read() == LOW) {
      Mouse.move(2, 0);
    }
    if (button4.read() == LOW) {
      Mouse.move(-2, 0);
    }

  } else if (mode == 2) {

    if (millis() - timer > maxTime) {
      int angle = -1;
      if (button1.read() != HIGH) {
        Keyboard.print("FRONTS");
        angle = 90;

      }
      if (button2.read() != HIGH) {
        Keyboard.print("BUTTS");
        angle = 270;
      }
      Joystick.hat(angle); // 0, 45, 90, 135, 180, 225, 270, 315, -1

      Joystick.button(1, button3.read() != HIGH);
      Joystick.button(2, button4.read() != HIGH);

      timer = millis();
    }
  } else if (mode == 3 ) {

    if (button1.fallingEdge()) {
      if (mouseAutoMover == 1) {
        mouseAutoMover = 0;
      } else {
        mouseAutoMover = 1;
      }
    }

    if (mouseAutoMover) {
      // move mouse
      int mouseX = mousePositions[mouseYTile][mouseXTile][0];
      int mouseY = mousePositions[mouseYTile][mouseXTile][1];

      Mouse.move(mouseX, mouseY);
      Mouse.move(mouseX, mouseY);
      Mouse.click();
      delay(1000);

      // reset mouse to origin // start
      Mouse.move(mouseX * -1, mouseY * -1);
      Mouse.move(mouseX * -1, mouseY * -1);

      //Get new mouse Tile Positions
      mouseXTile = (mouseXTile + 1) % mouseXTileMax;


      delay(100);
    }
  } else if (mode == 4) {
    radius = 10;
    int mouseX = cos(angle) * radius;
    int mouseY = sin(angle) * radius;

    if (button1.read() == LOW) {
      Mouse.move(mouseX, 0);
    }
    if (button2.read() == LOW) {
      Mouse.move(0, mouseY);
    }
    if (button3.fallingEdge()) {
      radius += 1;
    }
    if (button4.fallingEdge()) {
      radius -= 1;
    }
    angle += 0.1;
    delay(5);

  }
  */
}


void oldMidiMapTest() {
  //  // tetratonic test scale 2-1-1-3
//  if (button1.fallingEdge()) {
//    usbMIDI.sendNoteOn(60, 99, channel); // 60 = c4
//  }
//  if (button1.risingEdge()) {
//    usbMIDI.sendNoteOff(60, 0, channel);
//  }
//  if (button2.fallingEdge()) {
//    usbMIDI.sendNoteOn(62, 99, channel); // 60 = c4
//  }
//  if (button2.risingEdge()) {
//    usbMIDI.sendNoteOff(62, 0, channel);
//  }
//  if (button3.fallingEdge()) {
//    usbMIDI.sendNoteOn(63, 99, channel); // 60 = c4
//  }
//  if (button3.risingEdge()) {
//    usbMIDI.sendNoteOff(63, 0, channel);
//  }
//  if (button4.fallingEdge()) {
//    usbMIDI.sendNoteOn(64, 99, channel); // 60 = c4
//  }
//  if (button4.risingEdge()) {
//    usbMIDI.sendNoteOff(64, 0, channel);
//  }
}
