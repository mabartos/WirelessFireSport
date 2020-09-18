#include "Device.h"

#include <Arduino.h>

Device::Device(const long& id) : TopicsCommon(id), _id(id) {
}

Device::Device(const long& id, const string& topicPrefix) : TopicsCommon(id, topicPrefix), _id(id) {
}

void Device::init() {
}

void Device::reactToMessage(const string& topic, const JsonObject& obj) {
}

string Device::getName() {
    return _name;
}

void Device::setName(const string& name) {
    _name = name;
}

long Device::getID() {
    return _id;
}

// Calibration
void Device::calibrate() {
    _calibTime = millis();
}

long Device::getCalibTime() {
    return _calibTime;
}

void Device::setCalibTime(const long& time) {
    _calibTime = time;
}

bool Device::isCalibTimeChanged() {
    return _isCalibTimeChanged;
}

bool Device::isCalibrated() {
    return _isCalibrated;
}

void Device::setCalibrated(bool state) {
    _isCalibrated = state;
}