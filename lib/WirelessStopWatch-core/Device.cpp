#include "Device.h"

Device::Device(const long& id) : _id(id) {
}

void Device::init() {
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