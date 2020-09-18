#ifndef BART_MQTT_CLIENT_H
#define BART_MQTT_CLIENT_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <string>

using namespace std;

class BartMqttClient {
   private:
    string _id;
    bool _active = false;

    IPAddress _serverIP;
    uint16_t _serverPort;
    PubSubClient &_client;

    void callback(char *topic, uint8_t *payload, unsigned int length);

   public:
    BartMqttClient(const string id, const IPAddress &serverIP, const uint16_t serverPort);
    ~BartMqttClient() = default;

    void init();

    bool isActive();
    void setActive(bool state);
    string getID();
    IPAddress getServerIP();
    uint16_t getServerPort();
    PubSubClient &getClient();
};

#endif  //BART_MQTT_CLIENT_H