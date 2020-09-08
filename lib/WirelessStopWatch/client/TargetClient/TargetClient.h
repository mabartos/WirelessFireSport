#ifndef TARGET_CLIENT_H
#define TARGET_CLIENT_H
#include "../Client.h"

using namespace std;

class TargetClient : public Client {
   private:
    uint8_t _leftPin = -1;
    uint8_t _rightPin = -1;

    bool _leftState;
    bool _rightState;

    bool _activeLevel = 1;

   public:
    TargetClient(const long &id, const uint8_t &leftPin, const uint8_t &rightPin);
    ~TargetClient() = default;

    uint8_t getLeftPin();
    void setLeftPin(const long &pin);

    uint8_t getRightPin();
    void setRightPin(const long &pin);

    bool getActiveLevel();
    void setActiveLevel(const bool &activeLevel);

    void checkState();

    bool isLeftActive();
    bool isRightActive();
};

#endif  //TARGET_CLIENT_H