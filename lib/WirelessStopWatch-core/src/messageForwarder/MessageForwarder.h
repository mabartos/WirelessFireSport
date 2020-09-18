#ifndef MESSAGE_FORWARDER_H
#define MESSAGE_FORWARDER_H

#include <ArduinoJson.h>
#include <Device.h>

class MessageForwarder {
   protected:
    Device &_device;

   public:
    MessageForwarder(Device &device);
    ~MessageForwarder() = default;

    Device &getDevice();

    virtual void forwardMessage(const char *topic, DynamicJsonDocument &doc);
    virtual void forwardMessage(const char *topic, const char *data, uint32_t length);
};

#endif  //MESSAGE_FORWARDER_H