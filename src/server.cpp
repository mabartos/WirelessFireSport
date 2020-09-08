

#include <ESP8266WiFi.h>

#include <string>

#include "credentials.h"
#include "topics.h"
#include "uMQTTBroker.h"

using namespace std;

//------------------DECLARING VARIABLES---------------------//
//----------------------------------------------------------//
#define BUTTON D8
bool calibrating = false;
unsigned long calibrateTime = 0;
unsigned long calibTest = 0;

unsigned long startTime = 0;
unsigned long endTime = 0;

bool isStarted = false;
bool isEnded = false;

bool now = false;

//------------------FORWARD DECLARATION---------------------//
//----------------------------------------------------------//

void startWiFiClient();

String toString(const char *data);

void calibrateDevices();

class MQTTBroker : public uMQTTBroker {
   public:
    virtual bool onConnect(IPAddress addr, uint16_t client_count) {
        Serial.println(addr.toString() + " connected");
        return true;
    }

    virtual bool onAuth(String username, String password) {
        Serial.println("Username/Password: " + username + "/" + password);
        return true;
    }

    virtual void onData(String topic, const char *data, uint32_t length) {
        char data_str[length + 1];
        os_memcpy(data_str, data, length);
        data_str[length] = '\0';

        if ((topic.compareTo("com/master/end") == 0) && !isEnded) {
            endTime = millis();
            isEnded = true;
            Serial.println("END");
            Serial.println("TIME:");
            double time = (endTime - startTime);
            Serial.println(time);
        }
        if (topic.compareTo(t_masterCalib) == 0) {
            if ((toString(data_str).compareTo(t_calibEnd) == 0) && calibrating) {
                calibrateTime = millis();
                calibrating = false;
            }
        }

        Serial.println("received topic '" + topic + "' with data '" + data_str + "'");
    }
};

MQTTBroker myBroker;

//------------------MAIN---------------------//
//-------------------------------------------//

void setup() {
    pinMode(BUTTON, INPUT);
    Serial.begin(9600);
    delay(5000);
    // Start WiFi
    startWiFiClient();

    Serial.println("Starting MQTT broker");
    myBroker.init();
    myBroker.subscribe("com/master/#");
    calibrateDevices();
}

void loop() {
    if (!calibrating) {
        if ((digitalRead(BUTTON) == HIGH) && !isStarted) {
            startTime = millis();
            isStarted = true;
            Serial.println("START");
        }
        if (calibrateTime > 0) {
            Serial.println("eval:");
            Serial.println(calibrateTime - calibTest);

            Serial.println("Cal_time:");
            Serial.println(calibrateTime);
        }
    }
    delay(2);
}

//------------------OTHER FUNCTIONS---------------------//
//------------------------------------------------------//
String toString(const char *data) {
    String tmp(data);
    return tmp;
}

void startWiFiClient() {
    Serial.println("Connecting to " + (String)SSID);
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASS);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.println("WiFi connected");
    Serial.println("IP address: " + WiFi.localIP().toString());
}

void calibrateDevices() {
    calibrating = true;
    Serial.println("Kalibrace zarizeni");
    Serial.println("Zmacknete kalibracni tlacitko");
    while (1) {
        if (digitalRead(BUTTON) == HIGH) {
            calibTest = millis();
            myBroker.publish(t_slaveCalib, t_calibReady);
            Serial.println("Zmacknete kalibracni tlacitko u tercu");
            return;
        }
        delay(10);
    }
}
