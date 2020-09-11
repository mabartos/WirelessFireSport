#include "TargetsDevice.h"

#include "Arduino.h"

TargetsDevice::TargetsDevice(const long &id, const uint8_t &leftPin, const uint8_t &rightPin) : ClientDevice(id) {
    _leftPin = leftPin;
    _rightPin = rightPin;
}

void TargetsDevice::init() {
    pinMode(_leftPin, INPUT_PULLUP);
    pinMode(_rightPin, INPUT_PULLUP);
}

void TargetsDevice::checkState() {
    _leftState = digitalRead(_leftPin);
    _rightState = digitalRead(_rightPin);
}

uint8_t TargetsDevice::getLeftPin() {
    return _leftPin;
}
void TargetsDevice::setLeftPin(const long &pin) {
    _leftPin = pin;
}

uint8_t TargetsDevice::getRightPin() {
    return _rightPin;
}
void TargetsDevice::setRightPin(const long &pin) {
    _rightPin = pin;
}

bool TargetsDevice::getActiveLevel() {
    return _activeLevel;
}
void TargetsDevice::setActiveLevel(const bool &activeLevel) {
    _activeLevel = activeLevel;
}

bool TargetsDevice::isLeftActive() {
    return _leftState == getActiveLevel();
}
bool TargetsDevice::isRightActive() {
    return _rightState == getActiveLevel();
}