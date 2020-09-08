#ifndef CLIENT_H
#define CLIENT_H

#include "common/Device.h"
using namespace std;

class Client : public Device {
   private:
    bool _isConnected;

   public:
    Client(const long &id);
    ~Client() = default;

    bool isConnected();

    virtual void checkState() = 0;
};

#endif  //CLIENT_H