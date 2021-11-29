//library
#include <DHT.h>
//koneksi pin
DHT dht1(5, DHT11); 
DHT dht2(0, DHT11); 
DHT dht3(0, DHT11);  

void setup(){
  Serial.begin(9600); 
  dht1.begin();
  dht2.begin();
  dht3.begin();
}

void loop(){
  int humid1 = dht1.readHumidity();
  float temp1 = dht1.readTemperature();
  int humid2 = dht2.readHumidity();
  float temp2 = dht2.readTemperature();
  int humid3 = dht3.readHumidity();
  float temp3 = dht3.readTemperature();
 
  Serial.print(temp1);
  Serial.print(",");
  Serial.print(humid1);
  Serial.print(",");
  Serial.print(temp2);
  Serial.print(",");
  Serial.print(humid2);
  Serial.print(",");
  Serial.print(temp3);
  Serial.print(",");
  Serial.print(humid3);
  Serial.println(",");
  delay(1000);     
}
