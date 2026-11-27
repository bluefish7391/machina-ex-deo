
#include <Adafruit_SSD1306.h>
#include <OLED.h>

OLED::OLED() : display_(WIDTH, HEIGHT, &Wire, -1) {}

void OLED::begin() {
	display_.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display_.setTextColor(WHITE);
	display_.setTextSize(2);

	currentMessage_ = "";
}

void OLED::displayPower(uint8_t power) {
	char buf[MSG_LEN];
	snprintf(buf, sizeof(buf), "Power: %u/20", power);
	render(buf);
}

void OLED::render(const char* message) {
	if (strcmp(message, currentMessage_) == 0) return;

	display_.clearDisplay();
	display_.setCursor(0, 0);
	display_.print(message);
	display_.display();
}