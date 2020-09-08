#include "Server.h"

Server::Server(const long &id) : Device(0) {
}

string Server::getURL() {
    return _url;
}

void Server::setURL(const string &url) {
    _url = url;
}

uint16_t Server::getPort() {
    return _port;
}

void Server::setPort(const uint16_t &port) {
    _port = port;
}

// CLIENTS
uint16_t Server::getClientsCount() {
    return _clients.size();
}

vector<shared_ptr<Client>> Server::getClients() {
    return _clients;
}

void Server::addClient(shared_ptr<Client> client) {
    _clients.push_back(client);
}

void Server::removeClient(const long &id) {
    vector<shared_ptr<Client>> clients = getClients();
    for (unsigned i = 0; i < clients.size(); i++) {
        if (clients[i]->getID() == id) {
            _clients.erase(clients.begin() + i);
        }
    }
}
