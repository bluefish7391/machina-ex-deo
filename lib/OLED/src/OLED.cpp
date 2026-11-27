
#include <OLED.h>

void OLED::displayPower(uint8_t power) {
	render("test");
}

void OLED::render(const char* message) {
	if (strcmp(message, currentMessage_) == 0) return;

	display_.clearDisplay();
	display_.setCursor(0, 0);
	display_.print(message);
	display_.display();
}