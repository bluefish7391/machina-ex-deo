
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
	uint8_t target1 = 5;
	QTEBar_[target1] = TARGET_CHAR;
	QTEBar_[currentBarIdx_] = FOCUS_CHAR;

	lcd_.setLine(0, "[SPACE] FOR POWER");
	lcd_.setLine(1, QTEBar_);
	lcd_.update();
}

void QTEManager::updateQTE(unsigned long now) {
	if (space_.wasPressed()) {
		tapped_ = true;
	}

	if (now - lastQTEUpdate_ >= Config::QTE_FOCUS_MOVE_MS) {
		if (!tapped_ && onTarget_ || tapped_ && !onTarget_) {
			QTEBar_[currentBarIdx_] = MISS_CHAR;
			qteCurrentlySuccessful_ = false;
		} else if (tapped_ && onTarget_) {
			QTEBar_[currentBarIdx_] = HIT_CHAR;
		} else {
			QTEBar_[currentBarIdx_] = BLANK_CHAR;
		}

		tapped_ = false;
		onTarget_ = (QTEBar_[currentBarIdx_] == TARGET_CHAR);
		QTEBar_[++currentBarIdx_] = FOCUS_CHAR;

		lcd_.setLine(1, QTEBar_);
		lcd_.update();
	}
}

void QTEManager::endQTE() {
	if (qteCurrentlySuccessful_) {
		powerToCollect_ = Config::QTE_REWARD;
	}

	currentBarIdx_ = 0;
	onTarget_ = false;
	qteCurrentlySuccessful_ = true;
	for (uint8_t i = 0; i < WIDTH; i++) {
		QTEBar_[i] = BLANK_CHAR;
	}
}

bool QTEManager::QTEActive() {
	return state_ == QTEManagerState::Active;
}

uint8_t QTEManager::collectPower() {
	uint8_t power = powerToCollect_;
	powerToCollect_ = 0;
	return power;
}