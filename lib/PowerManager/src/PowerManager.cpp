
#include <PowerManager.h>

void PowerManager::runPassivePowerGen(unsigned long now) {
	if (now - lastPassivePowerGen_ >= Config::PASSIVE_POWER_GEN_MS) {
		power_++;
	}
}

void PowerManager::runQTE(unsigned long now) {
	if (now - lastQTE_ < Config::QTE_PERIOD_MS) return;
	// TBA
}