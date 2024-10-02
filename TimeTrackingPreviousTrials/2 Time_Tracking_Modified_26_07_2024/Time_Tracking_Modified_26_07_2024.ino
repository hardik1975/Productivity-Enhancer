/* 

  Date      : 25 July 2024
  Author    : Hardik Seth
  Objective :

*/

int setTime = 10;

#include "connect_wifi.h"
#include "ntp_time.h"

int i = setTime;

unsigned long previousMillis = 0;  
const long interval = 1000;        


void setup() 
{
  Serial.begin(115200);

  initWiFi("yo", "hardikhardik");

  ntpTimeConfig();

  previousEpochTime = getTime();
}

void loop() {
  currentEpochTime = getTime();

  unsigned long currentMillis = millis();

  // Overflow Detection for currentEpochTime and previousEpochTime
  if (currentEpochTime < previousEpochTime) { 
    previousEpochTime = currentEpochTime; 
  }

  // Overflow Detection for printing time
  if (currentMillis < previousMillis) { 
    previousMillis = currentMillis; 
  }


  if ((currentEpochTime - previousEpochTime) == setTime) 
  {
    Serial.println("Bhaiya 10 second ho gye");
    previousEpochTime = getTime();
    i = setTime;
  }

  else 
  {
    if (currentMillis - previousMillis >= interval) 
    {
      i--;
      Serial.println(i);

      // save the last time you blinked the LED
      previousMillis = currentMillis;
    }
  }
}