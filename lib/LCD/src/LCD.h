
#pragma once
#include <Arduino.h>
#include <LiquidCrystal.h>

class LCD {
public:
	LCD(uint8_t rs, uint8_t en, uint8_t d4,
		uint8_t d5, uint8_t d6, uint8_t d7);
	void begin();
	void setLine(uint8_t lineNum, const char* line);
	void update();
	
	static constexpr uint8_t COLS = 16, ROWS = 2;

private:
	LiquidCrystal lcd_;
	char currentMessage_[ROWS][COLS + 1];
	char buffer_[ROWS][COLS + 1];
};