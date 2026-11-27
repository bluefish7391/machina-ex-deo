
#pragma once
#include <Arduino.h>
#include <Adafruit_SSD1306.h>

enum OLEDState {
	DisplayingPower,
};

class OLED {
public:
	OLED();
	bool begin();
	void displayPower(uint8_t power);

private:
	OLEDState state_;
	Adafruit_SSD1306 display_;
	const char* currentMessage_;

	static constexpr uint8_t WIDTH = 128, HEIGHT = 64;
	
	void render(const char* message);
};