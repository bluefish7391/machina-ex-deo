
#pragma once
#include <Arduino.h>
#include <QTEManager.h>
#include <config.h>

QTEManager::QTEManager(LCD lcd, Button space) : lcd_(lcd) {}

void QTEManager::update(unsigned long now) {
	if (now - lastQTEStart_ >= Config::QTE_PERIOD_MS) {
		startQTE(now);
	}
}

void QTEManager::startQTE(unsigned long now) {
	
}

void QTEManager::updateQTE(unsigned long now) {

}

void endQTE() {
	
}