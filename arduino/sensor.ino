/*
  Questo è Sensorino
  File Principale
  È stato costruito da Alessandro Massarenti
  V 2.0
*/
#define AIR_TEMP "/home/greenhouse/airTemp"
#define AIR_HUMID "/home/greenhouse/airHumid"
#define SOIL_HUMID "/home/greenhouse/soilHumid"
#define ID_CONTROLLER "sensor_1"
#define USERNAME "username"
#define PASSWORD "password"
#define PAUSE_T 10000

#include <DHT.h>
#include <UIPEthernet.h> // Used for Ethernet
#include <PubSubClient.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xEE};
IPAddress server(192, 168, 51, 117);

DHT sensore(3, 22); // Sensor obj
int soilSensor = A0;

EthernetClient ethClient;
PubSubClient mqttClient(ethClient);

void reconnect()
{
  // Loop until we're reconnected
  while (!mqttClient.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (mqttClient.connect(ID_CONTROLLER, USERNAME, PASSWORD))
    {
      Serial.println("connected");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(9600);

  mqttClient.setServer(server, 1883);

  Ethernet.begin(mac);
  sensore.begin();
  // Allow the hardware to sort itself out
  delay(500);
}

void loop()
{
  float airTemp, airHumid, soilHumid;

  while(true){
    if (!mqttClient.connected())
    {
      reconnect();
    }

    soilHumid = analogRead(soilSensor);
    airTemp = sensore.readTemperature();
    airHumid = sensore.readHumidity();

    Serial.println(airTemp);
    Serial.println(airHumid);
    Serial.println(String(airTemp).c_str());
    mqttClient.publish(AIR_TEMP,  String(airTemp).c_str()  ,true);
    mqttClient.publish(AIR_HUMID, String(airHumid).c_str()  ,true);
    mqttClient.publish(SOIL_HUMID, String(soilHumid).c_str() ,true);
    delay(2000);
  }
}