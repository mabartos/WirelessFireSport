#include "ServerDevice.h"

ServerDevice::ServerDevice() : Device(0) {
}

ServerDevice::ServerDevice(const long &id) : Device(id) {
}

void ServerDevice::init() {
}

string ServerDevice::getURL() {
    return _url;
}

void ServerDevice::setURL(const string &url) {
    _url = url;
}

uint16_t ServerDevice::getPort() {
    return _port;
}

void ServerDevice::setPort(const uint16_t &port) {
    _port = port;
}

// CLIENTS
uint16_t ServerDevice::getClientsCount() {
    return _clients.size();
}

vector<shared_ptr<ClientDevice>> ServerDevice::getClients() {
    return _clients;
}

void ServerDevice::addClient(shared_ptr<ClientDevice> client) {
    _clients.push_back(client);
}

void ServerDevice::removeClient(const long &id) {
    vector<shared_ptr<ClientDevice>> clients = getClients();
    for (unsigned i = 0; i < clients.size(); i++) {
        if (clients[i]->getID() == id) {
            _clients.erase(clients.begin() + i);
        }
    }
}