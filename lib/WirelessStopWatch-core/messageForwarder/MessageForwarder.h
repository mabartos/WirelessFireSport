#ifndef MESSAGE_FORWARDER_H
#define MESSAGE_FORWARDER_H

#include <ArduinoJson.h>

class MessageForwarder {
   public:
    MessageForwarder() = default;
    ~MessageForwarder() = default;

    virtual void forwardMessage(char *topic, DynamicJsonDocument &doc) = 0;
};

#endif  //MESSAGE_FORWARDER_H