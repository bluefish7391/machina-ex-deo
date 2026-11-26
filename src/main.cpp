#include <Arduino.h>
#include <GameMaster.h>

GameMaster game;

void setup() { game.begin(); }
void loop() { game.update(millis()); }