#ifndef CLIENT_DEVICE_H
#define CLIENT_DEVICE_H

#include <Device.h>
using namespace std;

class ClientDevice : public Device {
   private:
    const string CLIENT_TOPIC_PREFIX = "client/";

    bool _isConnected;

   public:
    ClientDevice(const long &id);
    ~ClientDevice() = default;

    bool isConnected();

    virtual void checkState();
};

#endif  //CLIENT_DEVICE_H