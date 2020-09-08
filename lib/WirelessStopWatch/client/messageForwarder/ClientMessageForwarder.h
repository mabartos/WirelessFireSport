#ifndef CLIENT_MESSAGE_FORWARDER_H
#define CLIENT_MESSAGE_FORWARDER_H

#include "common/messageForwarder/MessageForwarder.h"

class ClientMessageForwader : public MessageForwarder {
   public:
    ClientMessageForwader() = default;
    ~ClientMessageForwader() = default;

    void forwardMessage(char *topic, DynamicJsonDocument &doc);
    void forwardMessage(char *topic, uint8_t *payload, unsigned int length);
};

#endif  //CLIENT_MESSAGE_FORWARDER_H