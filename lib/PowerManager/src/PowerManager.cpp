
#include <config.h>
#include <PowerManager.h>
#include <OLED.h>

PowerManager::PowerManager(QTEManager& qteManager) : qteManager_{qteManager} {}

void PowerManager::update(unsigned long now) {
	runPassivePowerGen(now);
	runQTE(now);
}

void PowerManager::runPassivePowerGen(unsigned long now) {
	if (now - lastPassivePowerGen_ >= Config::PASSIVE_POWER_GEN_MS) {
		changePower(Config::PASSIVE_POWER_GEN_REWARD);
		lastPassivePowerGen_ = now;
	}
}

void PowerManager::runQTE(unsigned long now) {
	qteManager_.update(now);
	if (qteManager_.QTEActive()) {
		return;
	}

	changePower(qteManager_.collectPower());
}

void PowerManager::changePower(uint8_t amount) {
	power_ += amount;
	power_ = min(20, max(power_, 0));
}