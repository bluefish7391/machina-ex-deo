
#include <config.h>
#include <PowerManager.h>
#include <OLED.h>

PowerManager::PowerManager(OLED& oled, QTEManager& qteManager) : oled_{oled}, qteManager_{qteManager} {}

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

void PowerManager::displayPower() {
	char buf[OLED::MSG_LEN];
	snprintf(buf, OLED::MSG_LEN, "Power:%u/20", power_);
	oled_.render(buf);
}