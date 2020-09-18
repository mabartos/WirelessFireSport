#ifndef TARGETS_DEVICE_H
#define TARGETS_DEVICE_H
#include <ArduinoJson.h>
#include <ClientDevice.h>

using namespace std;

class TargetsDevice : public ClientDevice {
   private:
    uint8_t _leftPin = -1;
    uint8_t _rightPin = -1;

    bool _leftState;
    bool _rightState;

    bool _activeLevel = 1;

   public:
    TargetsDevice(const long &id, const uint8_t &leftPin, const uint8_t &rightPin);
    ~TargetsDevice() = default;

    void init() override;
    void checkState() override;
    void reactToMessage(const string &topic, const JsonObject &obj) override;

    uint8_t getLeftPin();
    void setLeftPin(const long &pin);

    uint8_t getRightPin();
    void setRightPin(const long &pin);

    bool getActiveLevel();
    void setActiveLevel(const bool &activeLevel);

    bool isLeftActive();
    bool isRightActive();
};

#endif  //TARGETS_DEVICE_H