/* 
  Date      : 27 July 2024
  Author    : Hardik Seth
  Objective : 
*/

#include "countdown.h"
#include "timeManager.h"
#include "connectWiFi.h"

// unsigned long previousMillis = 0;  // will store last time LED was updated
// const long interval = 1000;  // interval at which to blink (milliseconds)

/* ------------------------- instance for WiFi Class ------------------------ */
connectWifi connectWifi("yo", "hardikhardik");

/* ------------------- instance for Time Management Class ------------------- */
timeManager t1("pool.ntp.org");

// Variable to save current epoch time
unsigned long currentEpochTime; 
unsigned long previousEpochTime;
 
void setup() 
{
  Serial.begin(115200);

  totalTime(0, 0, 20);

  remainingTime = totalTime(0, 0, 20);

  Serial.println(totalSeconds);
  
  connectWifi.initWifi();

  t1.initTime();

  previousEpochTime = t1.getTime();
}

void loop() 
{
  currentEpochTime = t1.getTime();

  unsigned long currentMillis = millis();

  // Overflow Detection for currentEpochTime and previousEpochTime
  if (currentEpochTime < previousEpochTime) { 
    previousEpochTime = currentEpochTime; 
  }

  if ((currentEpochTime - previousEpochTime) == totalSeconds) 
  {
    // while(1)
    // {
    //   Serial.println("Bhaiya Time ho gya :) ");
    //   Serial.println("Press reset btn to Restart ");
    // }
  } 
  else
  {
    remainingTime --;
  }

  Serial.println(currentEpochTime);
  // printTime(remainingTime);
    
}