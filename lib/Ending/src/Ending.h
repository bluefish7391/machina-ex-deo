
#pragma once
#include <Arduino.h>
#include <LCD.h>

enum class EndingType : uint8_t {
	Good
};

class Ending {
public:
	Ending(LCD lcd, EndingType type) : lcd_(lcd), type_(type) {}
	void update();

private:
	LCD lcd_;
	EndingType type_;
	uint8_t lastLinePrinted = 0;
};