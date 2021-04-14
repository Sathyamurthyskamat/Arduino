#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  
float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.println(String(t, 2)+"*C ---- "+ String(h, 2)+"%");
delay(1000);

}
