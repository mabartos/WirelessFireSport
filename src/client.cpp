#ifdef CLIENT

#include <Arduino.h>
#include <mqttClient/BartMqttClient.h>
#include <targetDevice/TargetsDevice.h>
#include <wifiManager/ClientWifiManager.h>

#include <string>

#include "credentials.h"
#include "topics.h"

using namespace std;

const string DEVICE_NAME = "targetClient";
const long DEVICE_ID = 1;

ClientWifiManager wifiManager(SSID, PASS);
TargetsDevice device(DEVICE_ID, D0, D1);
BartMqttClient mqttClient(DEVICE_NAME, SERVER_IP, BROKER_PORT);

void setup() {
    Serial.begin(9600);
    wifiManager.initWifi();
    mqttClient.init();
    device.init();

    device.calibrate();
}

void loop() {
    device.checkState();
    delay(10);
}

#endif  //CLIENT
