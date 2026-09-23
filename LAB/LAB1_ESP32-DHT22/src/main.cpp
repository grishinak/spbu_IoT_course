#include <Arduino.h>
#include "DHTesp.h"


DHTesp dht;

void setup() {
  Serial.begin(115200);
  dht.setup(3, DHTesp::DHT22);
}

void loop() {
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print("Humidity = "); Serial.println( humidity );
  Serial.print("Temperature = "); Serial.println( temperature );

  delay(2000);

}