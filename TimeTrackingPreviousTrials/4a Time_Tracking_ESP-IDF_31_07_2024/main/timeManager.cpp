#include "timeManager.h"

timeManager::timeManager(const char* ntpServer) : ntpServer(ntpServer){}

/* ------------------ Function that gets current epoch time ----------------- */
unsigned long timeManager::getTime() 
{
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) 
  {
    // Serial.println("Failed to obtain time");
    return 0;
  }
  time(&now);
  if (now < 1000000000) // Check if the epoch time is realistic
  { 
    return 0;
  }
  return now;
}


/* ----------------------------- Initialize time ---------------------------- */
void timeManager::initTime()
{
  configTime(0, 0, ntpServer);
}