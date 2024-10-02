#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "time.h"

class TimeManager {
public:
    TimeManager(const char* ntpServer);
    unsigned long getTime();
    void initTime();
private:
    const char* ntpServer;
};

#endif
