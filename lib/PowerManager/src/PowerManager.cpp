
#include <config.h>
#include <PowerManager.h>
#include <OLED.h>

PowerManager::PowerManager(OLED& oled) : oled_{oled} {}

void PowerManager::runPassivePowerGen(unsigned long now) {
	if (now - lastPassivePowerGen_ >= Config::PASSIVE_POWER_GEN_MS) {
		changePower(Config::PASSIVE_POWER_GEN_REWARD);
		lastPassivePowerGen_ = now;
	}
}

void PowerManager::runQTE(unsigned long now) {
	if (now - lastQTE_ < Config::QTE_PERIOD_MS) return;
	// TBA
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