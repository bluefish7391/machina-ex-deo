
#pragma once
#include <Arduino.h>
#include <config.h>

class OLED;

class PowerManager {
public:
	explicit PowerManager(OLED& oled);
	uint8_t getPower() { return power_; };
	void runPassivePowerGen(unsigned long now);
	void runQTE(unsigned long now);
	void changePower(uint8_t amount);
	void displayPower();

private:
	uint8_t power_ = Config::POWER_START;
	unsigned long lastPassivePowerGen_ = 0;
	unsigned long lastQTE_ = 0;

	OLED& oled_;
};