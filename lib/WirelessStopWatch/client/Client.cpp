#include "Client.h"

Client::Client(const long &id) : Device(id) {
}

bool Client::isConnected() {
    return _isConnected;
}