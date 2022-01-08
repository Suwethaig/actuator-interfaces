/*
 * The following code can be used to operate servo motor using serial commands.
 * 
 * Serial commands:
 * 0 - Move servo to 0 position
 * 1 - Move servo to 180 position from 0 position
 * 2 - Move servo to 0 position from 180 position
 * 
 * Author - Suwetha I G
 * 
 */
 
#include <Servo.h>

//Pin initialisation
static const int servoPin = 2;

Servo servo1;

void setup()
{
  //Initialise serial monitor
  Serial.begin(115200);

  servo1.attach(servoPin);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char a = Serial.read();
    if (a == '1')
    {
      for (int posDegrees = 0; posDegrees <= 180; posDegrees++)
      {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(5);
      }
    }
    else if (a == '2')
    {
      for (int posDegrees = 180; posDegrees >= 0; posDegrees--)
      {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(5);
      }
    }
    else if (a == '0')
    {
      servo1.write(0);
    }
  }
}
