//
// Created by mabartos on 9/19/19.
//


#ifndef PROJECTS_TOPICS_H
#define PROJECTS_TOPICS_HPP
#include <string>

String t_slaveCom = "com/slave/";
String t_slaveAll = t_slaveCom+"#";
String t_slaveConnect = t_slaveCom+("connect");
String t_slaveLeft = t_slaveCom+("left");
String t_slaveRight = t_slaveCom+("right");
String t_slaveCalib = t_slaveCom+("calib");

enum SlaveTopics {
    et_slaveCom,
    et_slaveAll,
    et_slaveConnect,
    et_slaveLeft,
    et_slaveRight,
    et_slaveCalib
};

String t_masterCom = "com/master/";
String t_masterAll = t_masterCom+("#");
String t_masterConnect = t_masterCom+("connect");
String t_masterCalib = t_masterCom+("calib");
String t_masterEnd = t_masterCom+("end");
String t_masterReady = t_masterCom+("ready");



enum MasterTopics {
    et_masterCom,
    et_masterAll,
    et_masterConnect,
    et_masterCalib,
    et_masterEnd,
    et_masterReady
};

String t_calibReady = "ready";
String t_calibNotReady = "not_ready";
String t_calibEnd="end";

String t_true = "true";
String t_false = "false";

#endif //PROJECTS_TOPICS_H
