#include "BartMqttBroker.h"

#include <ServerDevice.h>
#include <messageForwarder/ServerMessageForwarder.h>

extern ServerDevice device;

ServerMessageForwarder forwader(device);

BartMqttBroker::BartMqttBroker(const IPAddress &ipAddress, const uint16_t port) : uMQTTBroker(), _ipAddress(ipAddress), _port(port) {
}

BartMqttBroker::BartMqttBroker(const IPAddress &ipAddress, const uint16_t port, const string &username, const string &password) : uMQTTBroker(), _ipAddress(ipAddress), _port(port), _username(username), _password(password) {
}

string BartMqttBroker::getUsername() {
    return _username;
}

uint16_t BartMqttBroker::getPort() {
    return _port;
}

IPAddress BartMqttBroker::getIpAddress() {
    return _ipAddress;
}

bool BartMqttBroker::onConnect(IPAddress addr, uint16_t client_count) {
    Serial.println(addr.toString() + " connected");
    return true;
}

bool BartMqttBroker::onAuth(String username, String password) {
    if (_username == "" || _password == "")
        return true;
    return (strcmp(username.c_str(), username.c_str()) == 0 && strcmp(password.c_str(), _password.c_str()) == 0);
}

void BartMqttBroker::onData(String topic, const char *data, uint32_t length) {
    char data_str[length + 1];
    os_memcpy(data_str, data, length);
    data_str[length] = '\0';

    Serial.println("received topic '" + topic + "' with data '" + data_str + "'");
    forwader.forwardMessage(topic.c_str(), data, length);
}