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

void setup() {
  // put your setup code here, to run once:
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);

  //  delay(1000);
  //  button1.update();
  //  button2.update();
  delay(100);

  if (digitalRead(BUT1) == LOW ) {
    mode = 1;
  } else if (digitalRead(BUT2) == LOW ) {
    mode = 2;
  } else if (digitalRead(BUT3) == LOW) {
    mode = 3;
  } else if (digitalRead(BUT4) == LOW) {
    mode = 4;
  }

//  Serial.begin(9600);
//  Serial.println("Ardreamo by @kuwala");


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






if (button1.fallingEdge()) {
}
if (button1.risingEdge()) {
  Serial.println("button1 up");
}
if (button2.fallingEdge()) {
}
if (button2.risingEdge()) {
  Serial.println("button2 up");
}
if (button3.fallingEdge()) {
}
if (button3.risingEdge()) {
  Serial.println("button3 up");
}
if (button4.fallingEdge()) {
}
if (button4.risingEdge()) {
  Serial.println("button4 up");
}


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
