#ifdef CLIENT

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <stdlib.h>
#include <string>
#include "topics.h"
#include "credentials.h"

//------------------DECLARING VARIABLES---------------------//
//----------------------------------------------------------//
using namespace std;

#define BUTTON D0

unsigned long calibrateTime = 0;
bool connected;
long int returnedConnection = 0;

bool isEnded = false;

IPAddress ip(192, 168, 0, 106);
const int port = 1883;

WiFiClient wclient;
PubSubClient client(wclient);

//------------------FORWARD DECLARATION---------------------//
//----------------------------------------------------------//

int editTopics(char *topics);

void decodeMessage(char *topic, char *message);

void callback(char *topic, byte *payload, unsigned int length);

void setUpWifi();

void connectDevices();

void calibrateDevice();

String toString(const char *data);

//------------------MAIN---------------------//
//-------------------------------------------//

void setup() {
    pinMode(BUTTON, INPUT);
    Serial.begin(9600);
    delay(5000);
    setUpWifi();

    connectDevices();
}

void loop() {
    if ((digitalRead(BUTTON) == HIGH) && !isEnded) {
        client.publish("com/master/end", "");
        isEnded = true;
        Serial.println("ENDED");
    }
    if (calibrateTime > 0) {
        Serial.println(calibrateTime);
    }
    client.loop();
}

//------------------OTHER FUNCTIONS---------------------//
//------------------------------------------------------//
String toString(const char *data) {
    String tmp(data);
    return tmp;
}

void calibrateDevice() {
    Serial.println("Zmacknete kalibracni tlacitko");

    while (1) {
        if (digitalRead(BUTTON) == HIGH) {
            calibrateTime = millis();
            client.publish(t_masterCalib.c_str(), t_calibEnd.c_str());
            return;
        }
        delay(10);
    }
}

void connectDevices() {
    static bool isSent = false;
    if (!isSent) {
        client.publish(t_masterConnect.c_str(), "42");
        isSent = true;
    } else {
        connected = (returnedConnection == 43);
    }
}

int editTopics(char *topics) {
    String topic(topics);
    if (topic.compareTo(t_slaveCom) == 0)
        return et_slaveCom;
    else if (topic.compareTo(t_slaveAll) == 0)
        return et_slaveAll;
    else if (topic.compareTo(t_slaveCalib) == 0)
        return et_slaveCalib;
    else if (topic.compareTo(t_slaveConnect) == 0)
        return et_slaveConnect;
    else if (topic.compareTo(t_slaveLeft) == 0)
        return et_slaveLeft;
    else if (topic.compareTo(t_slaveRight) == 0)
        return et_slaveRight;
}

// Event handler
void decodeMessage(char *topic, char *message) {
    switch (editTopics(topic)) {
        case et_slaveCom:
            break;
        case et_slaveAll:
            break;
        case et_slaveCalib:
            Serial.println("MESS");
            Serial.println(toString(message));
            if (toString(message).compareTo(t_calibReady) == 0) {
                calibrateDevice();
            }
            break;
        case et_slaveConnect:
            returnedConnection = strtol(message, nullptr, 10);
            break;
        case et_slaveLeft:
            break;
        case et_slaveRight:
            break;
        default:
            break;
    }
}

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);

    Serial.print("Message:");

    char messageChar[length + 1];
    for (int i = 0; i < length; i++) {
        messageChar[i] = (char) payload[i];
    }
    messageChar[length] = '\0';

    decodeMessage(topic, messageChar);

    string message(messageChar);
    Serial.println(message.c_str());
    Serial.println();
    Serial.println("-----------------------");
}

void setUpWifi() {
    WiFi.begin(SSID, PASS);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Pripojovani k WiFi..");
    }
    Serial.println("Pripojeno do WiFi site ");

    client.setServer(ip, port);
    client.setCallback(callback);

    while (!client.connected()) {
        Serial.println("Pripojovani k centrale");

        if (client.connect("Terce")) {
            Serial.println("Bezdratove terce pripojeny");
        } else {
            Serial.println("Terce nejsou pripojeny");
            delay(2000);
        }
    }

    client.subscribe(t_slaveAll.c_str());
}

#endif