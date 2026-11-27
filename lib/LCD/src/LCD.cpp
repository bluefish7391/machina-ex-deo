
#include <LCD.h>

LCD::LCD(uint8_t rs, uint8_t en, uint8_t d4,
		uint8_t d5, uint8_t d6, uint8_t d7) 
		: lcd_(rs, en, d4, d5, d6, d7) {}

void LCD::begin() {
	lcd_.begin(COLS, ROWS);
}

void LCD::setLine(uint8_t lineNum, const char* line) {
	if (strncmp(currentMessage_[lineNum], line, COLS) == 0) return;
	strncpy(currentMessage_[lineNum], line, COLS);
	render();
}

void LCD::render() {
	lcd_.clear();
	lcd_.setCursor(0, 0);
	for (uint8_t i = 0; i < ROWS; i++) {
		lcd_.println(currentMessage_[i]);
	}
	
	lcd_.display();
}