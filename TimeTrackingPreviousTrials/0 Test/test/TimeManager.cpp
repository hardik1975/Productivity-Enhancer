#include "TimeManager.h"

TimeManager::TimeManager(const char* ntpServer) 
    : ntpServer(ntpServer) {}

unsigned long TimeManager::getTime() {
    time_t now;
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        return 0;
    }
    time(&now);
    if (now < 1000000000) {
        return 0;
    }
    return now;
}

void TimeManager::initTime() {
    configTime(0, 0, ntpServer);
}
