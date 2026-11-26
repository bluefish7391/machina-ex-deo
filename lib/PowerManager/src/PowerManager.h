
#pragma once
#include <Arduino.h>
#include <config.h>

class PowerManager {
public:
	uint8_t getPower() { return power_; };
	void runPassivePowerGen(unsigned long now);
	void runQTE(unsigned long now);

private:
	uint8_t power_ = Config::POWER_START;
	unsigned long lastPassivePowerGen_ = 0;
	unsigned long lastQTE_ = 0;
};