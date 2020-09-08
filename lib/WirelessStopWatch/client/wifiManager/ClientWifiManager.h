#ifndef WIFI_MANAGER_CLIENT_H
#define WIFI_MANAGER_CLIENT_H

#include <string>

#include "common/wifiManager/WifiManager.h"

using namespace std;

class ClientWifiManager : public WifiManager {
   public:
    ClientWifiManager(const string &ssid, const string &password);
    ~ClientWifiManager() = default;

    void initWifi();
};

#endif  //WIFI_MANAGER_CLIENT_H