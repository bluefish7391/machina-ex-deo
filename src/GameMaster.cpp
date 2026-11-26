
#include <GameMaster.h>

void GameMaster::begin() {
	space_.begin();
}

void GameMaster::update(unsigned long now) {
	space_.update(now);
}