#pragma once

#include "Arduino.h"
#include "time.h"

class timeManager
{
    private:
        /**
         * @brief Destruct a Servo instance.
         *
         * Call _() and detach().
         */
        const char* ntpServer;
        
    public:
        timeManager(const char* ntpServer);

        unsigned long getTime();
        void initTime();

};


