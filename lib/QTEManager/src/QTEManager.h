
#pragma once
#include <Arduino.h>
#include <LCD.h>
#include <Button.h>

enum class QTEManagerState : uint8_t {
	Idle,
	Wait,
	Active
};

class QTEManager {
public:
	QTEManager(LCD lcd, Button space);
	void begin(unsigned long now);
	void update(unsigned long now);
	bool QTEActive();
	uint8_t collectPower();

private:
	LCD lcd_;
	Button space_;
	static constexpr uint8_t WIDTH = 16, HEIGHT = 2;
	static constexpr char BLANK_CHAR = 'o';
	static constexpr char TARGET_CHAR = '*';
	static constexpr char HIT_CHAR = '$';
	static constexpr char MISS_CHAR = 'X';
	static constexpr char FOCUS_CHAR = '#';

	QTEManagerState state_ = QTEManagerState::Idle;
	unsigned long lastQTEStart_;
	unsigned long lastQTEUpdate_;
	char QTEBar_[WIDTH + 1];
	uint8_t currentBarIdx_ = 0;

	bool onTarget_ = false;
	bool tapped_ = false;
	bool qteCurrentlySuccessful_ = true;
	uint8_t powerToCollect_ = 0;

	void startQTE(unsigned long now);
	void updateQTE(unsigned long now);
	void endQTE();
};