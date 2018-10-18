/**************************************************************************
**  File: taskconfig.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 22.05.2018
**************************************************************************/
#ifndef TASKCONFIG_H
#define TASKCONFIG_H
#include <iostream>
enum class Options{
    taskCount = 0,
    assigmentTime,
    outputTime,
    lockTime,
    unlockTime,
    endTime,
    quantum
};
struct TaskConfig{
    u_char taskCount = 0;
    u_char assigmentTime = 0;
    u_char outputTime = 0;
    u_char lockTime = 0;
    u_char unlockTime = 0;
    u_char endTime = 0;
    u_char quantum = 0;
    u_char& operator[](u_char place){
        switch (place) {
            case 0 : return taskCount;
            case 1 : return assigmentTime;
            case 2 : return outputTime;
            case 3 : return lockTime;
            case 4 : return unlockTime;
            case 5 : return endTime;
            case 6 : return quantum;
            default: return taskCount;
        }
    }
};
#endif // TASKCONFIG_H
