#ifndef SERVER_WIFI_MANAGER_H
#define SERVER_WIFI_MANAGER_H

#include <wifiManager/WifiManager.h>

#include <string>

class ServerWifiManager : public WifiManager {
   protected:
    IPAddress _ipAddress;

   public:
    ServerWifiManager(const IPAddress ipAddress, const string &ssid, const string &pass);
    ServerWifiManager(const IPAddress ipAddress, const char *ssid, const char *password);
    ~ServerWifiManager() = default;

    IPAddress getIpAddress();

    void initWifi();
};

#endif  //SERVER_WIFI_MANAGER_H