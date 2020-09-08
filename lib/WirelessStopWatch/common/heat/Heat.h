#ifndef HEAT_H
#define HEAT_H
#include <string>

using namespace std;

class Heat {
   private:
    long _id = -1;
    long _leftResult = -1;
    long _rightResult = -1;

    bool _isTraining = true;
    string _teamName = "";

    bool _isStarted = false;
    bool _isReady = false;
    bool _isFinished = false;
    bool _isReseted = false;

   public:
    Heat(const long &id);
    Heat(const long &id, const string &teamName);
    ~Heat() = default;

    long getID();

    long getResult();

    string getTeamName();
    void setTeamName(const string &teamName);

    long getLeftResult();
    void setLeftResult(const long &result);

    long getRightResult();
    void setRightResult(const long &result);

    bool isTraining();
    void setIsTraining(bool state);

    bool isReady();
    void setIsReady(bool state);

    bool isFinished();
    void setIsFinished(bool state);

    bool isReseted();
    void setIsReseted(bool state);
};

#endif  //HEAT_H