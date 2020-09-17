#ifndef SERVER_MESSAGE_FORWARDER_H
#define SERVER_MESSAGE_FORWARDER_H

#include <messageForwarder/MessageForwarder.h>

class ServerMessageForwarder : MessageForwarder {
   public:
    ServerMessageForwarder() = default;
    ~ServerMessageForwarder() = default;

    void forwardMessage(char *topic, DynamicJsonDocument &doc);
    void forwardMessage(String topic, const char *data, uint32_t length);
};

#endif  //SERVER_MESSAGE_FORWARDER_H