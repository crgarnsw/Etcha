/**
 * TwoKnobEtcha.pde
 * This program creates a display for lines to be drawn on the screen in response to
 * input from an etcha sketch input device.
 *
 * This example code is in the public domain.
 */

import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
int x=0,y=0,ox=0,oy=0;
int ol=0, or=0;
color[] colors = {color(255,0,0),
                  color(0,255,0),
                  color(0,0,255),
                  color(255,255,0),
                  color(255,0,255),
                  color(0,255,255),
                  color(255,255,255),
                  color(0,0,0)
                 };
int colorI = 0;

void setup() {
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600); 
  size(displayWidth, displayHeight);
  background(0);
}

boolean sketchFullScreen() {
  return true;
}

void draw() {
  int l, r, index, dW = displayWidth-5, dH = displayHeight-5;
  stroke(colors[colorI]);
  strokeWeight(10);
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
    if(val != null) {
      
      if(val.charAt(0) == 'B') {
        colorI = (colorI + 1) % colors.length;
      } else {
        index = val.indexOf(',');
      
        l = int(val.substring(0,index));
        r = int(val.substring(index+1).trim());
      
        x = ox + (l-ol);
        y = oy + (r-or);
        
        x = x<5 ? 5 : x>dW ? dW : x;
        y = y<5 ? 5 : y>dH ? dH : y;
      
        ol = l;
        or = r;
      
        line(ox,oy,x,y);
      
        ox = x;
        oy = y;
      }
    }
  } 
}

