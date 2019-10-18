/*
  Questo è Sensorino
  File Principale
  È stato costruito da Alessandro Massarenti
  V 2.0
*/

#include "DHT.h"

String inputString = "";     // a String to hold incoming data
bool stringComplete = false; // whether the String is complete
DHT sensore1(2, 22);         // Sensor1 (air temp and humid)

void setup()
{
  Serial.begin(9600);
  inputString.reserve(200);
  sensore1.begin();
}

void loop()
{

  if (stringComplete)
  {
    if (inputString == "temp")
    {
      Serial.print("temp");
      Serial.println(sensore1.readTemperature());
    }
    else if (inputString == "humi")
    {
      Serial.print("humi");
      Serial.println(sensore1.readHumidity());
    }
    else
    {
      Serial.println(inputString);
    }
    // clear the String
    inputString = "";
    stringComplete = false;
  }

  // Clock
  delay(10);
}

void serialEvent()
{
  while (Serial.available())
  {
    char inChar = (char)Serial.read(); // get the new byte:
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n')
      stringComplete = true;
    else
      inputString += inChar; // add it to the inputString:
  }
}