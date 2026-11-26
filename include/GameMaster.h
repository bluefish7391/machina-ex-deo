#include <pins.h>
#include <Button.h>

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
};