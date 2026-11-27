
#pragma once
#include <Arduino.h>
#include <config.h>
#include <QTEManager.h>

class OLED;
class QTEManager;

class PowerManager {
public:
	PowerManager(OLED& oled, QTEManager& qteManager);
	uint8_t getPower() { return power_; };
	void update(unsigned long now);
	void changePower(uint8_t amount);
	void displayPower();

private:
	void runPassivePowerGen(unsigned long now);
	void runQTE(unsigned long now);

	uint8_t power_ = Config::POWER_START;
	unsigned long lastPassivePowerGen_ = 0;

	OLED& oled_;
	QTEManager& qteManager_;
};