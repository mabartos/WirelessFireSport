#include "ServerWifiManager.h"

ServerWifiManager::ServerWifiManager(const IPAddress ipAddress, const string &ssid, const string &pass) : WifiManager(ssid, pass), _ipAddress(ipAddress) {
}

ServerWifiManager::ServerWifiManager(const IPAddress ipAddress, const char *ssid, const char *password) : WifiManager(ssid, password), _ipAddress(ipAddress) {
}

IPAddress ServerWifiManager::getIpAddress() {
    return _ipAddress;
}

void ServerWifiManager::initWifi() {
    Serial.printf("Connecting to %s.", _ssid.c_str());
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid.c_str(), _pass.c_str());

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("WiFi connected");
    setActive(true);
    setIpAddress(WiFi.localIP());
}