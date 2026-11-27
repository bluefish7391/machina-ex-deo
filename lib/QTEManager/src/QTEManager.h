
#pragma once
#include <Arduino.h>
#include <LCD.h>
#include <Button.h>

class QTEManager {
public:
	QTEManager(LCD lcd, Button space);
	void update(unsigned long now);
	bool getLastQTEWasSuccessful();

private:
	LCD lcd_;
	Button space_;
	static constexpr uint8_t WIDTH = 16, HEIGHT = 2;

	unsigned long lastQTEStart_ = 0;
	unsigned long lastQTEUpdate_ = 0;
	char QTEBar[WIDTH + 1] = "oooooooooooooooo";
	uint8_t currentBarIdx_ = 0;

	bool active_ = false;
	bool onTarget = false;
	bool qteCurrentSuccess_ = true;
	bool lastQTEWasSuccessful = false;

	void startQTE(unsigned long now);
	void updateQTE(unsigned long now);
	void endQTE();
};