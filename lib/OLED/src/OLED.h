
#pragma once
#include <Arduino.h>
#include <Adafruit_SSD1306.h>

enum OLEDState {
	DisplayingPower,
};

class OLED {
public:
	OLED();
	void begin();
	void render(const char* message);

	static constexpr uint8_t MSG_LEN = 32;

private:
	OLEDState state_;
	Adafruit_SSD1306 display_;

	static constexpr uint8_t WIDTH = 128, HEIGHT = 64;
	char currentMessage_[MSG_LEN] = "";
};