#ifndef BART_MQTT_BROKER_H
#define BART_MQTT_BROKER_H
#include <ESP8266WiFi.h>
#include <uMQTTBroker.h>

#include <string>
using namespace std;

class BartMqttBroker : public uMQTTBroker {
   private:
    uint16_t _port;
    IPAddress _ipAddress;
    string _username = "";
    string _password = "";

   public:
    BartMqttBroker(const IPAddress &ipAddress, const uint16_t port);
    BartMqttBroker(const IPAddress &ipAddress, const uint16_t port, const string &username, const string &password);
    ~BartMqttBroker() = default;

    string getUsername();
    uint16_t getPort();
    IPAddress getIpAddress();

    bool onConnect(IPAddress addr, uint16_t client_count);
    bool onAuth(String username, String password);
    void onData(String topic, const char *data, uint32_t length);
};

#endif  //BART_MQTT_BROKER_H
