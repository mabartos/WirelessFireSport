#ifndef CLIENT_MESSAGE_FORWARDER_H
#define CLIENT_MESSAGE_FORWARDER_H

#include <ArduinoJson.h>
#include <messageForwarder/MessageForwarder.h>

class ClientMessageForwarder : public MessageForwarder {
   public:
    ClientMessageForwarder() = default;
    ~ClientMessageForwarder() = default;

    void forwardMessage(char *topic, DynamicJsonDocument &doc) override;
    void forwardMessage(char *topic, uint8_t *payload, unsigned int length);
};

#endif  //CLIENT_MESSAGE_FORWARDER_H