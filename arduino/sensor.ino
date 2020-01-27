/*
  Questo è Sensorino
  File Principale
  È stato costruito da Alessandro Massarenti
  V 2.0
*/
#include <DHT.h>
#include <UIPEthernet.h> // Used for Ethernet

String readString = ""; // a String to hold incoming data
int interval = 5000;
unsigned long time, pvtime;
float temp, humid;
// **** ETHERNET SETTING ****
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xEE};
IPAddress ip(192, 168, 51, 55);

DHT sensore(3, 22);        // Sensor obj
EthernetServer server(80); // Ethernet obj

void setup()
{
  pvtime = millis();
  readString.reserve(100);

  sensore.begin();

  Ethernet.begin(mac, ip); // start the Ethernet connection and the server:
  server.begin();
  Serial.begin(9600);
}

void loop()
{
  // Create a client connection
  EthernetClient client = server.available();
  if (client)
  {
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();

        //read char by char HTTP request
        if (readString.length() < 100)
        {
          //store characters to string
          readString += c;
        }

        //if HTTP request has ended– 0x0D is Carriage Return \n ASCII
        if (c == 0x0D)
        {
          if (millis() - pvtime >= interval)
          {
            // save the last time you blinked the LED
            pvtime = millis();

            temp = sensore.readTemperature();
            humid = sensore.readHumidity();
            Serial.println(temp);
            Serial.println(humid);
          }
          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: application/json");
          client.println();
          
          client.println("{\"data\": {\"temperature\":" + String(temp) + ",\"humidity\":" + String(humid) + "}}");

          delay(10);
          //stopping client
          client.stop();

          //clearing string for next read
          readString = "";
        }
      }
    }
  }

  // Clock
  delay(20);
}