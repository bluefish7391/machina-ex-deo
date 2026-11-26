
#include <GameMaster.h>

void GameMaster::begin() {
	space_.begin();
}

void GameMaster::update(unsigned long now) {
	space_.update(now);

	switch (state_) {
		case GameState::Title:
			if (space_.wasPressed()) {
				state_ = GameState::Playing;
				break;
			}
		case GameState::Playing:
			break;
		case GameState::Won:
			break;
	}
}