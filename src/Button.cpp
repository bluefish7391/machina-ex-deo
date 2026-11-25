#include <Button.h>

void Button::begin() {
	pinMode(pin_, INPUT);
}

void Button::update(unsigned long now) {
	pressedEvent_ = false;
	releasedEvent_ = false;
	bool reading = (digitalRead(pin_) == HIGH);

	if (reading != rawState_) {
		rawState_ = reading;
		lastChange_ = now;
	}

	if (now - lastChange_ >= DEBOUNCE_MS && rawState_ != stableState_) {
		stableState_ = rawState_;
		if (stableState_) pressedEvent_ = true;
		else releasedEvent_ = false;
	}
}