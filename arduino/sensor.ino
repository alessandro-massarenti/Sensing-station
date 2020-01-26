/*
  Questo è Sensorino
  File Principale
  È stato costruito da Alessandro Massarenti
  V 2.0
*/

#include "DHT.h" // DHT sensor
#include <UIPEthernet.h> // Ethernet shield library

String inputString = "";     // a String to hold incoming data
bool stringComplete = false; // whether the String is complete
DHT sensore1(2, 22);         // Sensor1 (air temp and humid)

// **** ETHERNET SETTING ****
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xEE};
IPAddress ip(192, 168, 51, 55);
EthernetServer server(80);

String readString;

void setup()
{
  Serial.begin(9600);
  inputString.reserve(200);
  sensore1.begin();
}

void loop()
{
  EthernetClient client = server.available();
  if(client)
  {
    
  }




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