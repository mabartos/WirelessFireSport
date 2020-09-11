#include <ESP8266WiFi.h>

#include "stdio.h"
#include "stdlib.h"

const IPAddress SERVER_IP(192, 168, 68, 68);
const char* SSID = "WirelessStopWatchTest";
const char* PASS = "WirelessTest";
const uint16_t BROKER_PORT = 1883;