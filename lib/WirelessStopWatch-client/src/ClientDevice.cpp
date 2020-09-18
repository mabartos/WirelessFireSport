#include "ClientDevice.h"

ClientDevice::ClientDevice(const long &id) : Device(id) {
    setTopicPrefix(CLIENT_TOPIC_PREFIX);
}

bool ClientDevice::isConnected() {
    return _isConnected;
}

void ClientDevice::checkState() {}
