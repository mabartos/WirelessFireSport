#ifndef SERVER_WIFI_MANAGER_H
#define SERVER_WIFI_MANAGER_H

#include <string>

#include "common/wifiManager/WifiManager.h"

class ServerWifiManager : public WifiManager {
   protected:
    IPAddress _ipAddress;

   public:
    ServerWifiManager(const IPAddress ipAddress, const string &ssid, const string &pass);
    ~ServerWifiManager() = default;

    IPAddress getIpAddress();

    void initWifi();
};

#endif  //SERVER_WIFI_MANAGER_H