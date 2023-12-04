#include <Arduino.h>
#include <Adafruit_ILI9341.h>

#include "esp32-hal-gpio.h"

#define BUTTON_UP 2
#define BUTTON_DOWN 4
#define BUTTON_SEL 15

#define TFT_DC 32
#define TFT_CS 5

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int tela;
int cursor = 0;

void tela_inicial(int& tela){
	tft.setCursor(0,0);
	tft.setTextSize(3);
	tft.println("Tela inicial: \n");
	tft.setTextSize(2);

	// Controle da posição do cursor
	if (!digitalRead(BUTTON_UP)) {
		cursor++;
		tft.fillRect(0, 40, 15, 100, ILI9341_BLACK);
		delay(100);
	} 
	else if (!digitalRead(BUTTON_DOWN)) {
		cursor--;
		tft.fillRect(0, 40, 15, 100, ILI9341_BLACK);
		delay(100);
	}

	if (cursor > 2) cursor -= 3;
	else if (cursor < 0) cursor += 3;

	switch (cursor) {
		case 0:
			tft.write(16);
			tft.println("Temperatura \n");
			tft.println(" Velocidade \n");
			tft.println(" Modo \n");
			break;
		case 1:
			tft.println(" Temperatura \n");
			tft.write(16);
			tft.println("Velocidade \n");
			tft.println(" Modo \n");
			break;
		case 2:
			tft.println(" Temperatura \n");
			tft.println(" Velocidade \n");
			tft.write(16);
			tft.println("Modo \n");
			break;
	}
}


void setup(){
	Serial.begin(115200);

	pinMode(BUTTON_UP, INPUT_PULLUP);
	pinMode(BUTTON_DOWN, INPUT_PULLUP);
	pinMode(BUTTON_SEL, INPUT_PULLUP);

	tft.begin();

	tft.setTextColor(ILI9341_WHITE);
	tft.setTextSize(2);
	tft.setRotation(1);
	tft.fillScreen(ILI9341_BLACK);

	tela = 1;
}


void loop(){
	switch(tela){
		case 1:{
			tela_inicial(tela);
			break;
		}
	}
	delay(50);
}
