
#pragma once
#include <Arduino.h>
#include <QTEManager.h>
#include <config.h>

QTEManager::QTEManager(LCD lcd, Button space) : lcd_(lcd), space_(space) {}

void QTEManager::begin(unsigned long now) {
	lastQTEStart_ = now;
	lastQTEUpdate_ = now;

	for (uint8_t i = 0; i < WIDTH; i++) {
		QTEBar_[i] = BLANK_CHAR;
	}
}

void QTEManager::update(unsigned long now) {
	switch (state_) {
		case QTEManagerState::Idle: 
			if (now - lastQTEStart_ >= Config::QTE_PERIOD_MS) {
				startQTE(now);
			}
			break;
		case QTEManagerState::Wait:
			if (now - lastQTEStart_ >= Config::QTE_WAIT_MS) {
				state_ = QTEManagerState::Active;
				lastQTEUpdate_ = now;
			}
			break;
		case QTEManagerState::Active:
			if (currentBarIdx_ == WIDTH) {
				endQTE();
			} else {
				updateQTE(now);
			}
			break;
	}
}

void QTEManager::startQTE(unsigned long now) {
	
}

void QTEManager::updateQTE(unsigned long now) {

}

void QTEManager::endQTE() {
	
}