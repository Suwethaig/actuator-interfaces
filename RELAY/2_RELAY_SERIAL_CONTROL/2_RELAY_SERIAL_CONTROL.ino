/*
   The following code can be used to control relay using commands from the serial monitor.

   1 - Relay 1 ON
   2 - Relay 1 OFF
   3 - Relay 2 ON
   4 - Relay 2 OFF
   5 - Both relay ON
   6 - Both relay OFF

   Author: Suwetha I G
   
*/


#define relay_1 13 //Relay 1 pin
#define relay_2 10 //Relay 2 pin

void setup()
{
  //Initialise serial monitor
  Serial.begin(115200);

  //Pin initialisation
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char read_value = Serial.read();
    if (read_value == '1')
    {
      digitalWrite(relay_1, HIGH);
      Serial.println("Relay 1 is on");
    }
    else if (read_value == '2')
    {
      digitalWrite(relay_1, LOW);
      Serial.println("Relay 1 is off");
    }
    else if (read_value == '3')
    {
      digitalWrite(relay_2, HIGH);
      Serial.println("Relay 2 is on");
    }
    else if (read_value == '4')
    {
      digitalWrite(relay_2, LOW);
      Serial.println("Relay 2 is off");
    }
    else if (read_value == '5')
    {
      digitalWrite(relay_1, HIGH);
      digitalWrite(relay_2, HIGH);
      Serial.println("Both relay are on");
    }
    else if (read_value == '6')
    {
      digitalWrite(relay_1, LOW);
      digitalWrite(relay_2, LOW);
      Serial.println("Both relay are off");
    }
  }
}
