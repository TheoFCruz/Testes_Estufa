#include <Arduino.h>

#define STEP 12
#define DIR 14

void setup(){
	Serial.begin(115200);	

	pinMode(STEP, OUTPUT);
	pinMode(DIR, OUTPUT);
}

void loop(){
	digitalWrite(DIR, HIGH);
	for (int i = 0; i < 200; i++) {
		digitalWrite(STEP, HIGH);
		digitalWrite(STEP, LOW);
		delayMicroseconds(2000);
	}

	delay(1000);

	digitalWrite(DIR, LOW);
	for (int i = 0; i < 200; i++) {
		digitalWrite(STEP, HIGH);
		digitalWrite(STEP, LOW);
		delayMicroseconds(2000);
	}

	delay(1000);
}
