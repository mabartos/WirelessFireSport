#ifndef CLIENT_MESSAGE_FORWARDER_H
#define CLIENT_MESSAGE_FORWARDER_H

#include <ArduinoJson.h>
#include <messageForwarder/MessageForwarder.h>

class ClientMessageForwarder : public MessageForwarder {
   public:
    ClientMessageForwarder(Device &device);
    ~ClientMessageForwarder() = default;
};

#endif  //CLIENT_MESSAGE_FORWARDER_H