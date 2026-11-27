
#include <Adafruit_SSD1306.h>
#include <OLED.h>

OLED::OLED() : display_(WIDTH, HEIGHT, &Wire, -1) {}

void OLED::begin() {
	display_.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display_.setTextColor(WHITE);
	display_.setTextSize(2);
}

void OLED::render(const char* message) {
	if (strcmp(message, currentMessage_) == 0) return;

	strncpy(currentMessage_, message, MSG_LEN - 1);
	currentMessage_[MSG_LEN - 1] = '\0';

	display_.clearDisplay();
	display_.setCursor(0, 0);
	display_.print(message);
	display_.display();
}