#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "time.h"
#include "Arduino.h"

// const char* ntpServer = "pool.ntp.org";

class timeManager
{
    private:
        const char* ntpServer;
        
    public:
        timeManager(const char* ntpServer);

        unsigned long getTime();
        void initTime();

};


#endif