#include <Arduino.h>
#include <DHT.h>

DHT Sensor(26, DHT22);

void setup(){
	Serial.begin(115200);
	Sensor.begin();
}

float temperature = Sensor.readTemperature();

void loop(){
	Serial.println(temperature);
	temperature = Sensor.readTemperature();

  delay(100);
}

