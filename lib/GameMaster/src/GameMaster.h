#include <pins.h>
#include <Button.h>
#include <PowerManager.h>
#include <OLED.h>

enum class GameState : uint8_t {
	Title,
	Playing,
	Won
};

class GameMaster {
public:
	void begin();
	void update(unsigned long now);

private:
	Button space_{Pins::SPACE};
	GameState state_ = GameState::Title;
	PowerManager powerManager_;
	OLED oled_;

	void updateTitle(unsigned long now);
	void updatePlaying(unsigned long now);
	void updateWon(unsigned long now);
};