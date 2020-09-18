#ifndef SERVER_MESSAGE_FORWARDER_H
#define SERVER_MESSAGE_FORWARDER_H

#include <messageForwarder/MessageForwarder.h>

class ServerMessageForwarder : public MessageForwarder {
   public:
    ServerMessageForwarder(Device &device);
    ~ServerMessageForwarder() = default;
};

#endif  //SERVER_MESSAGE_FORWARDER_H