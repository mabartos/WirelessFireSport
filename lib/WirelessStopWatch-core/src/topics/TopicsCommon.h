#ifndef TOPICS_COMMON_H
#define TOPICS_COMMON_H

using namespace std;

#include <string>
#include <vector>

class TopicsCommon {
   private:
    long _deviceID;

    const string longToString(const long& number);

   protected:
    string _topicPrefix = "";
    vector<string> _topics;

    long getDeviceID();

   public:
    TopicsCommon(const long& id);
    TopicsCommon(const long& id, const string& topicPrefix);

    ~TopicsCommon() = default;

    string getTopicPrefix();
    void setTopicPrefix(const string& topicPrefix);

    const string getDeviceTopic();
    const string getDeviceTopicWildCard();
    const string getResetTopic();
    const string getStartTopic();
    const string getCalibTopic();

    vector<string> getTopics();
    void setTopics(const vector<string> topics);
    void addTopic(const string& topic);
    bool containsTopic(const string& topic);
};

#endif  //TOPICS_COMMON_H