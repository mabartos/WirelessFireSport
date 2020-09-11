#include "ClientDevice.h"

ClientDevice::ClientDevice(const long &id) : Device(id) {
}

bool ClientDevice::isConnected() {
    return _isConnected;
}