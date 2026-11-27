#pragma once
#include <Arduino.h>

namespace Config {
	//===============================================
	// General Power
	//===============================================
	constexpr uint8_t POWER_TO_WIN = 20;
	constexpr uint8_t POWER_START = 5;
	constexpr uint8_t POWER_COST_CAMERA = 1;
	constexpr uint8_t POWER_COST_PROXIMITY = 1;
	constexpr uint8_t POWER_COST_FLASH = 2;

	//===============================================
	//QTE
	//===============================================
	constexpr uint8_t QTE_TAPS = 2;
	constexpr unsigned long PASSIVE_POWER_GEN_MS = 20000;
	constexpr unsigned long QTE_PERIOD_MS = 20000;
	constexpr unsigned long QTE_WAIT_MS = 500;
	constexpr unsigned long QTE_FOCUS_MOVE_MS = 200;
}