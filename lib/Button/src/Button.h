#pragma once
#include <Arduino.h>

class Button {
public:
	explicit Button(uint8_t pin): pin_(pin) {}

	void begin();
	void update(unsigned long now);
	bool wasPressed() const { return pressedEvent_; }
	bool wasReleased() const { return releasedEvent_; }
	bool isHeld() const { return stableState_; }

private:
	static constexpr unsigned long DEBOUNCE_MS = 25;

	uint8_t pin_;
	bool rawState_ = false;
	bool stableState_ = false;
	bool pressedEvent_ = false;
	bool releasedEvent_ = false;
	unsigned long lastChange_ = 0;
};