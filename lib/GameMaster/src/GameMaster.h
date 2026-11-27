#include <pins.h>
#include <Button.h>
#include <PowerManager.h>
#include <OLED.h>
#include <LCD.h>
#include <QTEManager.h>

enum class GameState : uint8_t {
	Title,
	Playing,
	Won
};

class GameMaster {
public:
	GameMaster();
	void begin();
	void update(unsigned long now);

private:
	Button space_{Pins::SPACE};
	GameState state_ = GameState::Title;
	OLED oled_;
	LCD lcd_;
	QTEManager qteManager_{lcd_, space_};
	PowerManager powerManager_;

	void updateTitle(unsigned long now);
	void updatePlaying(unsigned long now);
	void updateWon(unsigned long now);
};