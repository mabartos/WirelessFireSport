#ifndef WIFI_MANAGER_CLIENT_H
#define WIFI_MANAGER_CLIENT_H

#include <wifiManager/WifiManager.h>

#include <string>

using namespace std;

class ClientWifiManager : public WifiManager {
   public:
    ClientWifiManager(const string &ssid, const string &password);
    ClientWifiManager(const char *ssid, const char *password);
    ~ClientWifiManager() = default;

    void initWifi() override;
};

#endif  //WIFI_MANAGER_CLIENT_H