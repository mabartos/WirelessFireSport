#ifndef SERVER_H
#define SERVER_H

#include <memory>
#include <string>
#include <vector>

#include "client/Client.h"
#include "common/Device.h"

using namespace std;

class Server : public Device {
   private:
    string _url;
    uint16_t _port;
    vector<shared_ptr<Client>> _clients;

   public:
    Server(const long &id);
    ~Server() = default;

    string getURL();
    void setURL(const string &url);

    uint16_t getPort();
    void setPort(const uint16_t &port);

    // CLIENTS
    uint16_t getClientsCount();
    vector<shared_ptr<Client>> getClients();
    void addClient(shared_ptr<Client> client);
    void removeClient(const long &id);
};
#endif  //SERVER_H