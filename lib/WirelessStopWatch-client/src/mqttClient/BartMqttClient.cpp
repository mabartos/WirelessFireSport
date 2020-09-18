#include "BartMqttClient.h"

#include <messageForwarder/ClientMessageForwarder.h>
#include <targetDevice/TargetsDevice.h>

extern TargetsDevice device;

WiFiClient wclient;
PubSubClient client(wclient);
ClientMessageForwarder forwarder(device);

BartMqttClient::BartMqttClient(const string id, const IPAddress &serverIP, const uint16_t serverPort) : _client(client), _id(id), _serverIP(serverIP), _serverPort(serverPort) {
    client.setServer(_serverIP, _serverPort);
    client.setCallback([this](char *topic, uint8_t *payload, unsigned int length) { this->callback(topic, payload, length); });
}

void BartMqttClient::init() {
    while (!_client.connected()) {
        Serial.println("Pripojovani k centrale");

        if (_client.connect(_id.c_str())) {
            break;
        }

        //todo subscribe
    }
}

void BartMqttClient::callback(char *topic, uint8_t *payload, unsigned int length) {
    forwarder.forwardMessage(topic, (char *)payload, length);
}

string BartMqttClient::getID() {
    return _id;
}

bool BartMqttClient::isActive() {
    return _active;
}
void BartMqttClient::setActive(bool state) {
    _active = state;
}

IPAddress BartMqttClient::getServerIP() {
    return _serverIP;
}
uint16_t BartMqttClient::getServerPort() {
    return _serverPort;
}
PubSubClient &BartMqttClient::getClient() {
    return _client;
}