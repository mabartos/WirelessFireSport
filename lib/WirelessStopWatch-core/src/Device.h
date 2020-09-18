#ifndef DEVICE_H
#define DEVICE_H

#include <ArduinoJson.h>
#include <topics/TopicsCommon.h>

#include <string>
#include <vector>

using namespace std;

class Device : public TopicsCommon {
   protected:
    string _name;
    long _id;

    long _calibTime;
    bool _isCalibTimeChanged = false;
    bool _isCalibrated = false;

    void setCalibTime(const long& time);
    void setCalibrated(bool state);

   public:
    Device(const long& id);
    Device(const long& id, const string& topicPrefix);
    ~Device() = default;

    virtual void init();
    virtual void reactToMessage(const string& topic, const JsonObject& obj);

    void calibrate();

    string getName();
    void setName(const string& name);

    long getID();

    long getCalibTime();
    bool isCalibTimeChanged();
    bool isCalibrated();
};

#endif  //DEVICE_H