#include "TopicsCommon.h"

#include <Arduino.h>
#include <topics/Topics.h>

#include <sstream>

TopicsCommon::TopicsCommon(const long& id) : _deviceID(id) {
}

TopicsCommon::TopicsCommon(const long& id, const string& topicPrefix) : _deviceID(id), _topicPrefix(topicPrefix) {
}

long TopicsCommon::getDeviceID() {
    return _deviceID;
}

string TopicsCommon::getTopicPrefix() {
    return _topicPrefix;
}

void TopicsCommon::setTopicPrefix(const string& topicPrefix) {
    _topicPrefix = topicPrefix;
}

vector<string> TopicsCommon::getTopics() {
    return _topics;
}

void TopicsCommon::setTopics(const vector<string> topics) {
    _topics = topics;
}

void TopicsCommon::addTopic(const string& topic) {
    _topics.push_back(topic);
}

bool TopicsCommon::containsTopic(const string& topic) {
    for (auto& innerTopic : getTopics()) {
        if (strcmp(topic.c_str(), innerTopic.c_str()) == 0)
            return true;
    }
    return false;
}

// CONST TOPICS

const string TopicsCommon::getDeviceTopic() {
    return (_topicPrefix != "") ? _topicPrefix + longToString(_deviceID) : "";
}

const string TopicsCommon::getDeviceTopicWildCard() {
    return (getDeviceTopic() != "") ? getDeviceTopic() + "#" : "";
}

const string TopicsCommon::getResetTopic() {
    return (getDeviceTopic() != "") ? getDeviceTopic() + Topics::RESET : "";
}

const string TopicsCommon::getStartTopic() {
    return (getDeviceTopic() != "") ? getDeviceTopic() + Topics::START : "";
}

const string TopicsCommon::getCalibTopic() {
    return (getDeviceTopic() != "") ? getDeviceTopic() + Topics::CALIB : "";
}

const string TopicsCommon::longToString(const long& number) {
    ostringstream stream;
    stream << number;
    return stream.str();
}