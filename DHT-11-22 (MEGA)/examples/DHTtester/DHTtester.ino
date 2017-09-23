#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Falha na leitura do sensor DHT!");
    return;
  }

  float hi = dht.computeHeatIndex(f, h);
  Serial.print("Umidade: "); 
  Serial.print(h);
  Serial.print(" %  ");
  Serial.print("Temperatura: "); 
  Serial.print(t);
  Serial.print("*C  ");
  Serial.print(f);
  Serial.print("*F  ");
  Serial.print("Indice de calor: ");
  Serial.print(hi);
  Serial.println("*F");
}
