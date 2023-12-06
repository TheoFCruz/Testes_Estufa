#include <Arduino.h>
#include <DHT.h>

#define LED 21 
#define POT 33

DHT Sensor(18, DHT22);

void setup(){
	Serial.begin(115200);
	Sensor.begin();

	pinMode(LED, OUTPUT);
	pinMode(POT, INPUT);
}

float current_temp = Sensor.readTemperature();
float target_temp = 25.0;

void loop(){
	// //Imprime as informacoes no monitor serial
	// Serial.print("Temperatura atual: ");
	// Serial.println(current_temp);
	// Serial.print("Temperatura alvo: ");
	// Serial.println(target_temp);
	//
	// //Atualiza as temperaturas
	// if (digitalRead(UP) == 0) target_temp++;
	// if (digitalRead(DOWN) == 0) target_temp--;
	//
	// current_temp = Sensor.readTemperature();
	//
	// //Pisca o LED (ou nao)
	// if (current_temp > target_temp) digitalWrite(LED, HIGH);	
	// else digitalWrite(LED, LOW);
	// 
	// delay(100);
	Serial.println(analogRead(POT));	
	delay(100);
}
