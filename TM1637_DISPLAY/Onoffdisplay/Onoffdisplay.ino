/*
 * The following code can be used to operate the ON OFF DISPLAY
 * Turn on the segment you want by assigning it value 1.
 * 
 * |-A-|
 * F   B
 * |-G-|
 * E   C
 * |-D-|
 * 
 */
#include <TM1637Display.h>

//Use OFF[] to turn off all the lights
const uint8_t OFF[] = {0, 0, 0, 0};

//The byte order is .GFEDCBA
const uint8_t ON[] = {B00000000,B00111111, B0110111,B00000000};
const uint8_t OFF[] = {B00000000,B00111111, B01110001,B01110001};

TM1637Display display(23, 5);//Pins used for I2C Connection

void setup(){
  
  // Set brightness of the LED
  display.setBrightness(4);
  
  // Clear the display
  display.setSegments(OFF);
}

void displayOn() {
  display.setSegments(ON);
  delay(2000);
}

void displayOff() {
  display.setSegments(OFF);
  delay(2000);
}

void loop()
{
  displayOn();
  displayOff();
}
