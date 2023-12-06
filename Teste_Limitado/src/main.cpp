#include <Arduino.h>
#include <DHT.h>

#define LED 21 
#define POT 2 

#define MAX_T_TEMP 40.0
#define MIN_T_TEMP 0.0

DHT Sensor(18, DHT22);

float analog_to_temp(int analog) {
	float m = (MAX_T_TEMP - MIN_T_TEMP)/(4095);
	return (MIN_T_TEMP + m*analog);
}

void blink_led(float temp_diff) {
	float blink_delay = 1000/(temp_diff + 1);

	digitalWrite(LED, HIGH);
	delay(blink_delay);	
	digitalWrite(LED, LOW);
	delay(blink_delay);	
}

void setup(){
	Serial.begin(115200);
	Sensor.begin();

	pinMode(LED, OUTPUT);
	pinMode(POT, INPUT);
}

float current_temp = Sensor.readTemperature();
float target_temp = 25.0;

void loop(){
	//Imprime as informacoes no monitor serial
	Serial.print("Temperatura atual: ");
	Serial.println(current_temp);
	Serial.print("Temperatura alvo: ");
	Serial.println(target_temp);

	//Atualiza as temperaturas
	target_temp = analog_to_temp(analogRead(POT));

	current_temp = Sensor.readTemperature();

	//Pisca o LED (ou nao)
	if (current_temp > target_temp) blink_led(current_temp - target_temp);	
	else digitalWrite(LED, LOW);

	delay(100);
}
