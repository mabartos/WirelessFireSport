#ifdef CLIENT

#include <string>

#include "client/mqttClient/BartMqttClient.h"
#include "client/targetDevice/TargetsDevice.h"
#include "client/wifiManager/ClientWifiManager.h"
#include "credentials.h"
#include "topics.h"

using namespace std;

const string DEVICE_NAME = "targetClient";
const long DEVICE_ID = 1;

ClientWifiManager wifiManager(SSID, PASS);
BartMqttClient mqttClient(DEVICE_NAME, SERVER_IP, BROKER_PORT);
TargetsDevice device(DEVICE_ID, D0, D1);

void setup() {
    Serial.begin(9600);
    wifiManager.initWifi();
    mqttClient.init();
    device.init();
}

void loop() {
    device.checkState();
    delay(10);
}

#endif  //CLIENT
