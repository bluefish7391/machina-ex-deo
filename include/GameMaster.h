#include <pins.h>
#include <Button.h>

class GameMaster {
public:
	void begin();
	void update(unsigned long now);

private:
	Button space_{Pins::SPACE};
};