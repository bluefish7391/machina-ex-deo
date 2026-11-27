#include <GameMaster.h>
#include <config.h>

void GameMaster::begin() {
	space_.begin();
	oled_.begin();
}

void GameMaster::update(unsigned long now) {
	space_.update(now);

	switch (state_) {
		case GameState::Title: updateTitle(now); break;
		case GameState::Playing: updatePlaying(now); break;
		case GameState::Won: updateWon(now); break;
	}
}

//===============================================
// Game state specific update methods
//===============================================

void GameMaster::updateTitle(unsigned long now) {
	if (space_.wasPressed()) state_ = GameState::Playing;
}

void GameMaster::updatePlaying(unsigned long now) {
	powerManager_.runPassivePowerGen(now);
	if (powerManager_.getPower() >= Config::POWER_TO_WIN) {
		state_ = GameState::Won;
		return;
	}

	uint8_t power = powerManager_.getPower();
	oled_.displayPower(power);

	// All prototype updates, input handling, outputs, etc. go here

	powerManager_.runQTE(now); // Only if available
}

void GameMaster::updateWon(unsigned long now) {}