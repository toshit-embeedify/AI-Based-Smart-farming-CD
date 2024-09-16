#include "DHT.h"
//#define DHTPIN 4     /* for arduino Nano pin 4 for DHT11 sensor input*/
#define DHTPIN 2     //for node mcu

#define DHTTYPE DHT11   /*DHT sensor type we are using*/
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();   /*Starts DHT sensor*/
}
void loop() {
  delay(2000);

  float h = dht.readHumidity(); /*float variable that stores humidity value*/
  float t = dht.readTemperature(); /*float variable that store temperature in Celsius*/
  //float f = dht.readTemperature(true); /*variable to store temperature in Fahrenheit*/
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print(F("Humidity: ")); /*prints humidity value*/
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C ")); /*prints temp in Celsius*/
}