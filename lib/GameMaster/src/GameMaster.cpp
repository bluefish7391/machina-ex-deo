#include <GameMaster.h>

void GameMaster::begin() {
	space_.begin();
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
	// TBA
}

void GameMaster::updateWon(unsigned long now) {}