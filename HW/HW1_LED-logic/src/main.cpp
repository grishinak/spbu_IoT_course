#include <Arduino.h>
#include "DHTesp.h"

DHTesp dht;
const int LED_GREEN = 5;
const int LED_YELLOW = 4;

void setup() {
  Serial.begin(115200);
  dht.setup(3, DHTesp::DHT22);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
}

void loop() {
// Счтывание с датчика показаний
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
// Печать показаний в терминал
Serial.printf("Temp: %.1f °C \t Humidity: %.1f %%\r\n", temperature, humidity);

// Логика зажигания светодиодов
// На температуру
  if (temperature > 50) {
    digitalWrite(LED_GREEN, true); 
    Serial.printf("LED_GREEN ON\r\n");
  } else {
    digitalWrite(LED_GREEN, false);  
  }
// На влажность
  if (humidity < 40) {
    digitalWrite(LED_YELLOW, true); 
    Serial.printf("LED_YELLOW ON\r\n");
  } else {
    digitalWrite(LED_YELLOW, false);  
  }

// Задержка 2 сек
  delay(2000);
}