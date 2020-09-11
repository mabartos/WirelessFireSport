#ifdef SERVER

#include <string>

#include "credentials.h"
#include "server/ServerDevice.h"
#include "server/mqttBroker/BartMqttBroker.h"
#include "server/wifiManager/ServerWifiManager.h"

using namespace std;

ServerWifiManager wifiManager(SERVER_IP, SSID, PASS);
ServerDevice device;
BartMqttBroker broker(SERVER_IP, BROKER_PORT);

void setup() {
    wifiManager.initWifi();
    device.init();
}

void loop() {
}

#endif  //SERVER
