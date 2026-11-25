#pragma once
#include <Arduino.h>

namespace Pins {
	// OLED
	constexpr uint8_t OLED_SDA = 20;
	constexpr uint8_t OLED_SLC = 21;
	
	// LCD
	constexpr uint8_t LCD_RS = 22;
    constexpr uint8_t LCD_EN = 23;
    constexpr uint8_t LCD_D4 = 24;
    constexpr uint8_t LCD_D5 = 25;
    constexpr uint8_t LCD_D6 = 26;
    constexpr uint8_t LCD_D7 = 27;
}