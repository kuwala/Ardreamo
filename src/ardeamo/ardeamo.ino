#include <Encoder.h>
#include <Bounce.h>

// Ardeamo v2 Teensy 3.2 Code
// by Daniel Smolentsev
// started 2-14-18

// Quick Version 1 TODO: 
// Get button input

// send midi usb cc notes for button input

// get encoder input
// send encoder cc

// record notes/documentation
// pin layout

// --- future

// add pet interface
// send serial data?? 

// refactor into interface_manager class

#define BUT1 5
#define BUT2 6
#define BUT3 7
#define BUT4 8

// Add 104 capacitors from encoder pins a and b to ground
// To do some debouncing.
#define ENCODER1A 1
#define ENCODER1B 2

#define ENCODER2A 3
#define ENCODER2B 4

Encoder knobRight(ENCODER2A, ENCODER2B);
long positionRight = -999;

Bounce button1 = Bounce(BUT1, 5); // 5ms debounce
Bounce button2 = Bounce(BUT2, 5); // 5ms debounce
Bounce button3 = Bounce(BUT3, 5); // 5ms debounce
Bounce button4 = Bounce(BUT4, 5); // 5ms debounce

// Midi
const int channel = 1;

// Joystick Timer
unsigned long timer = 0;
int maxTime = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Ardreamo by @kuwala");


}

void loop() {
  // put your main code here, to run repeatedly:

  long newRight;
  newRight = knobRight.read();

  if (newRight != positionRight) {
    Serial.print("Right = ");
    Serial.println(newRight);
    positionRight = newRight;
  }

  button1.update();
  button2.update();
  button3.update();
  button4.update();


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

  
if (millis() - timer > maxTime) {
  int angle = -1;
  if (button1.read() != HIGH) {
    Keyboard.print("FRONTS");
    angle = 90;
    
  }
  if (button2.read()!= HIGH) {
    Keyboard.print("BUTTS");
    angle = 270;
  }
  Joystick.hat(angle); // 0, 45, 90, 135, 180, 225, 270, 315, -1

  Joystick.button(1, button3.read()!= HIGH);
  Joystick.button(2, button4.read()!= HIGH);
  
  timer = millis();
}

}
