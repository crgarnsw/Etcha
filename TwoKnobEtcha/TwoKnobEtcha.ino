/* 
 * TwoKnobEtcha.ino
 * This program is loaded on an Arduino with two Rotary Encoders attached.  The program
 * running on the PC is able to interpret this input to simulate an Etcha Sketch (for example).
 *
 * This Encoder Library - TwoKnobs Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knobLeft(2, 4);
Encoder knobRight(3, 5);
int b1=0, b2=0;
int lastChange=0;

//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
//  Serial.println("TwoKnobs Encoder Test:");
}

long positionLeft  = -999;
long positionRight = -999;

void loop() {
  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (abs(newLeft - positionLeft) > 4 ||
      abs(newRight - positionRight) > 4) {
    Serial.print(newLeft);
    Serial.print(",");
    Serial.print(newRight);
    Serial.println();
    positionLeft = newLeft;
    positionRight = newRight;
    
  }
  
  if(!digitalRead(9)) {
    if(!b1 && (millis() - lastChange) > 200) {
      Serial.println("B1");
      b1 = 1;
      lastChange = millis();
    }
  } else if((millis() - lastChange) > 200) {
    b1 = 0;
    lastChange = millis();
  }
  
  if(!digitalRead(10)) {
    if(!b2 && (millis() - lastChange) > 200) {
      Serial.println("B2");
      b2 = 1;
      lastChange = millis();
    }
  } else if((millis() - lastChange) > 200) {
    b2 = 0;
    lastChange = millis();
  }
    
    
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
//    Serial.println("Reset both knobs to zero");
    knobLeft.write(0);
    knobRight.write(0);
  }
}
