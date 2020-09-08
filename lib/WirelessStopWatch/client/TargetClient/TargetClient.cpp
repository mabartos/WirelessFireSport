#include "TargetClient.h"

#include "Arduino.h"

TargetClient::TargetClient(const long &id, const uint8_t &leftPin, const uint8_t &rightPin) : Client(id) {
    _leftPin = leftPin;
    _rightPin = rightPin;
}

void TargetClient::checkState() {
    _leftState = digitalRead(_leftPin);
    _rightState = digitalRead(_rightPin);
}

uint8_t TargetClient::getLeftPin() {
    return _leftPin;
}
void TargetClient::setLeftPin(const long &pin) {
    _leftPin = pin;
}

uint8_t TargetClient::getRightPin() {
    return _rightPin;
}
void TargetClient::setRightPin(const long &pin) {
    _rightPin = pin;
}

bool TargetClient::getActiveLevel() {
    return _activeLevel;
}
void TargetClient::setActiveLevel(const bool &activeLevel) {
    _activeLevel = activeLevel;
}

bool TargetClient::isLeftActive() {
    return _leftState == getActiveLevel();
}
bool TargetClient::isRightActive() {
    return _rightState == getActiveLevel();
}