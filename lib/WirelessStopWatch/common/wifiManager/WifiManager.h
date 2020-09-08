#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <ESP8266WiFi.h>

#include <string>
using namespace std;

class WifiManager {
   protected:
    string _ssid;
    string _pass;
    uint16_t _port;
    IPAddress _ipAddress;
    bool _active = false;

   public:
    WifiManager(const string &ssid, const string &password);
    ~WifiManager() = default;

    string getSSID();

    uint16_t getPort();
    void setPort(const uint16_t &port);

    IPAddress getIpAddress();
    void setIpAddress(const IPAddress &ip);

    bool isActive();
    void setActive(bool state);

    virtual void initWifi() = 0;
};

#endif  //WIFI_MANAGER_H