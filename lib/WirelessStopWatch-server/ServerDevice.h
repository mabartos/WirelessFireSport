#ifndef SERVER_DEVICE_H
#define SERVER_DEVICE_H

#include <ClientDevice.h>
#include <Device.h>

#include <memory>
#include <string>
#include <vector>

using namespace std;

class ServerDevice : public Device {
   private:
    string _url = "";
    uint16_t _port = -1;
    vector<shared_ptr<ClientDevice>> _clients;

   public:
    ServerDevice();
    ServerDevice(const long &id);
    ~ServerDevice() = default;

    void init();

    string getURL();
    void setURL(const string &url);

    uint16_t getPort();
    void setPort(const uint16_t &port);

    // CLIENTS
    uint16_t getClientsCount();
    vector<shared_ptr<ClientDevice>> getClients();
    void addClient(shared_ptr<ClientDevice> client);
    void removeClient(const long &id);
};
#endif  //SERVER_DEVICE_H