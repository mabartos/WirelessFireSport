#include "MessageForwarder.h"

MessageForwarder::MessageForwarder(Device &device) : _device(device) {
}

Device &MessageForwarder::getDevice() {
    return _device;
}

void MessageForwarder::forwardMessage(const char *topic, DynamicJsonDocument &doc) {
    const string topicString = topic;
    getDevice().reactToMessage(topicString, doc.as<JsonObject>());
    doc.shrinkToFit();
    doc.garbageCollect();
}

void MessageForwarder::forwardMessage(const char *topic, const char *data, uint32_t length) {
    DynamicJsonDocument doc(512);
    DeserializationError err = deserializeJson(doc, data, length);
    if (err) {
        Serial.println(err.c_str());
        return;
    }

    forwardMessage(topic, doc);
}