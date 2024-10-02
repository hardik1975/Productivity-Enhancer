
#include "time.h"

// NTP server to request epoch time
const char* ntpServer = "pool.ntp.org";

// Variable to save current epoch time
unsigned long currentEpochTime; 
unsigned long previousEpochTime; 


// Function to config time in Void Setup
void ntpTimeConfig(){
  configTime(0, 0, ntpServer);
}


// Function that gets current epoch time
unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) 
  {
    Serial.println("Failed to obtain time");
    return 0;
  }
  time(&now);
  if (now < 1000000000) 
  { // Check if the epoch time is realistic
    Serial.println("Epoch time error");
    return 0;
  }
  return now;
}