#ifndef DEVICE_H
#define DEVICE_H

#include <string>

using namespace std;

class Device {
   protected:
    string _name;
    long _id;
    long _calibTime;
    bool _isCalibTimeChanged = false;
    bool _isCalibrated = false;

   public:
    Device() = default;
    Device(const long& id);
    ~Device() = default;

    virtual void init();

    string getName();
    void setName(const string& name);

    long getID();

    long getCalibTime();
    void setCalibTime(const long& time);

    bool isCalibTimeChanged();

    bool isCalibrated();
    void setCalibrated(bool state);
};

#endif  //DEVICE_H