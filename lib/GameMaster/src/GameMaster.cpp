#include <GameMaster.h>
#include <config.h>

GameMaster::GameMaster() : powerManager_(qteManager_) {}

void GameMaster::begin() {
	unsigned long now = millis();

	space_.begin();
	oled_.begin();
	lcd_.begin();
	qteManager_.begin(now);
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
	powerManager_.update(now);
	if (powerManager_.getPower() >= Config::POWER_TO_WIN) {
		state_ = GameState::Won;
		return;
	}

	uint8_t power = powerManager_.getPower();
	char buf[OLED::MSG_LEN];
	snprintf(buf, OLED::MSG_LEN, "Power:%u/20", power);
	oled_.render(buf);

	// All prototype updates, input handling, outputs, etc. go here
}

void GameMaster::updateWon(unsigned long now) {}