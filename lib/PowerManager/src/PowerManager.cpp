
#include <PowerManager.h>
#include <OLED.h>

PowerManager::PowerManager(OLED& oled) : oled_{oled} {}

void PowerManager::runPassivePowerGen(unsigned long now) {
	if (now - lastPassivePowerGen_ >= Config::PASSIVE_POWER_GEN_MS) {
		power_++;
		lastPassivePowerGen_ = now;
	}
}

void PowerManager::runQTE(unsigned long now) {
	if (now - lastQTE_ < Config::QTE_PERIOD_MS) return;
	// TBA
}

void PowerManager::displayPower() {
	char buf[OLED::MSG_LEN];
	snprintf(buf, OLED::MSG_LEN, "Power:%u/20", power_);
	oled_.render(buf);
}