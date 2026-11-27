
#pragma once
#include <Arduino.h>
#include <LCD.h>
#include <Button.h>

class QTEManager {
public:
	QTEManager(LCD lcd, Button space);
	void begin(unsigned long now);
	void update(unsigned long now);
	bool getLastQTEWasSuccessful();

private:
	LCD lcd_;
	Button space_;
	static constexpr uint8_t WIDTH = 16, HEIGHT = 2;
	static constexpr char BLANK_CHAR = 'o';
	static constexpr char TARGET_CHAR = '*';
	static constexpr char FOCUS_CHAR = '#';
	static constexpr char HIT_CHAR = '$';
	static constexpr char MISS_CHAR = 'X';

	unsigned long lastQTEStart_;
	unsigned long lastQTEUpdate_;
	char QTEBar_[WIDTH + 1];
	uint8_t currentBarIdx_ = 0;

	bool active_ = false;
	bool onTarget = false;
	bool qteCurrentSuccess_ = true;
	bool lastQTEWasSuccessful = false;

	void startQTE(unsigned long now);
	void updateQTE(unsigned long now);
	void endQTE();
};