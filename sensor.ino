#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print(h);
  Serial.print(",");
  Serial.println(t);
  delay(30000);
}
