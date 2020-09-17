#include "ClientWifiManager.h"

ClientWifiManager::ClientWifiManager(const char *ssid, const char *password) : WifiManager(ssid, password) {
}

ClientWifiManager::ClientWifiManager(const string &ssid, const string &password) : WifiManager(ssid, password) {
}

void ClientWifiManager::initWifi() {
    WiFi.begin(_ssid.c_str(), _pass.c_str());

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Pripojovani k WiFi..");
    }

    setActive(true);
    setIpAddress(WiFi.localIP());
    Serial.printf("Pripojeno do WiFi site %s.", _ssid.c_str());
}