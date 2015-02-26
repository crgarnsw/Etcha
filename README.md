# Etcha

Etcha Sketch program with Hardware Controls

Two rotary encoders are attached to an Arduino, which interfaces to the PC.  I have written an Etcha Sketch example program, but it could also be Pong, missle command, ect.

The encoders that I use have an additional push button control that can be used like a trigger (I use it to change the colors that are being displayed).

##Setup 
The Encoder library is in the TwoKnob directory, be sure to copy that to your Arduino libraries folder.

I have each of the two encoders hooked up to an interrupt pin and a regular digital input.

**Encoder #1: Pin 2 and 4 + the button is 9**

**Encoder #2: Pin 3 and 5 + the button is 10.**

##Hardware
![Encoders](https://raw.githubusercontent.com/crgarnsw/Etcha/master/encoders.jpg)

These encoders are attached to the pins above and ground, the button input is setup as a pull-up.

![Arduino](https://raw.githubusercontent.com/crgarnsw/Etcha/master/arduino.jpg)

This is the arduino, it is screwed into some runners along the edge of the box top.  It was pretty lucky that it fit into the box as well as it does.  I just found a box at the dollar store, drilled holes in the lid for the encoders and used a dremel to cut out a spot for the usb connector.

![Complete](https://raw.githubusercontent.com/crgarnsw/Etcha/master/complete.jpg)

Here it is all closed up and looking very professional :)