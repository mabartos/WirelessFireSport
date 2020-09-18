#ifndef TOPICS_H
#define TOPICS_H

using namespace std;
#include <string>

class Topics {
   public:
    static const string RESET;
    static const string START;
    static const string CALIB;

    static const string READY;
    static const string NOT_READY;
    static const string END;
};

const string Topics::RESET = "/reset";
const string Topics::START = "/start";
const string Topics::CALIB = "/calib";

const string Topics::READY = "/ready";
const string Topics::NOT_READY = "/not-ready";
const string Topics::END = "/end";

#endif  //TOPICS_H