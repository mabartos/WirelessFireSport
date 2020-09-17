#ifdef SERVER

#include <Arduino.h>
#include <ServerDevice.h>
#include <mqttBroker/BartMqttBroker.h>
#include <wifiManager/ServerWifiManager.h>

#include <string>

#include "credentials.h"

using namespace std;

ServerWifiManager wifiManager(SERVER_IP, SSID, PASS);
ServerDevice device;
BartMqttBroker broker(SERVER_IP, BROKER_PORT);

void setup() {
    wifiManager.initWifi();
    device.init();
    broker.init();
}

void loop() {
}

#endif  //SERVER
