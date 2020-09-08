#include "Heat.h"

Heat::Heat(const long &id) : _id(id) {
}

Heat::Heat(const long &id, const string &teamName) : _id(id), _teamName(teamName) {}

long Heat::getID() {
    return _id;
}

long Heat::getResult() {
    const long &left = getLeftResult();
    const long &right = getRightResult();
    if (left != -1 && right != -1) {
        return (left >= right) ? left : right;
    }
    return -1;
}

string Heat::getTeamName() {
    return _teamName;
}

void Heat::setTeamName(const string &teamName) {
    _teamName = teamName;
}

long Heat::getLeftResult() {
    return _leftResult;
}
void Heat::setLeftResult(const long &result) {
    _leftResult = result;
}

long Heat::getRightResult() {
    return _rightResult;
}
void Heat::setRightResult(const long &result) {
    _rightResult = result;
}

bool Heat::isTraining() {
    return _isTraining;
}
void Heat::setIsTraining(bool state) {
    _isTraining = state;
}

bool Heat::isReady() {
    return _isReady;
}
void Heat::setIsReady(bool state) {
    _isReady = state;
}

bool Heat::isFinished() {
    return _isFinished;
}
void Heat::setIsFinished(bool state) {
    _isFinished = state;
}

bool Heat::isReseted() {
    return _isReseted;
}
void Heat::setIsReseted(bool state) {
    _isReseted = state;
}