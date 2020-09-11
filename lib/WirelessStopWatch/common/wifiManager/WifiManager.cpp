#include "WifiManager.h"
WifiManager::WifiManager(const string &ssid, const string &password) : _ssid(ssid), _pass(password) {}

WifiManager::WifiManager(const char *ssid, const char *password) : _ssid(ssid), _pass(password) {
}

uint16_t WifiManager::getPort() {
    return _port;
}
void WifiManager::setPort(const uint16_t &port) {
    _port = port;
}

string WifiManager::getSSID() {
    return _ssid;
}

IPAddress WifiManager::getIpAddress() {
    return _ipAddress;
}

void WifiManager::setIpAddress(const IPAddress &ip) {
    _ipAddress = ip;
}

bool WifiManager::isActive() {
    return _active;
}
void WifiManager::setActive(bool state) {
    _active = state;
}
