/* 

  Date      : 25 July 2024
  Author    : Hardik Seth
  Objective :

*/


#include <WiFi.h>
#include "time.h"

int i = 0;

unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 1000;  // interval at which to blink (milliseconds)

// Replace with your network credentials
const char* ssid = "yo";
const char* password = "hardikhardik";

// NTP server to request epoch time
const char* ntpServer = "pool.ntp.org";

// Variable to save current epoch time
unsigned long epochTime; 
unsigned long epochTime1; 

// Function that gets current epoch time
unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    //Serial.println("Failed to obtain time");
    return 0;
  }
  time(&now);
  if (now < 1000000000) { // Check if the epoch time is realistic
    return 0;
  }
  return now;
}

// Initialize WiFi
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 20000) { // 20s timeout
    Serial.print('.');
    delay(1000);
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect to WiFi");
    // Handle error or retry logic
  } else {
    Serial.println(WiFi.localIP());
  }
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  configTime(0, 0, ntpServer);

  epochTime1 = getTime();
}

void loop() 
{
  epochTime = getTime();

  unsigned long currentMillis = millis();
  if (currentMillis < previousMillis) { // Detect overflow
    previousMillis = currentMillis; // Reset the previousMillis
  }

  if ((epochTime - epochTime1) == 10) {
    Serial.println("Bhaiya 10 second ho gye");
    epochTime1 = getTime();
    i = 0;
  } else {
    if (currentMillis - previousMillis >= interval) {
      i++;
      Serial.println(i);

      // save the last time you blinked the LED
      previousMillis = currentMillis;
    }
  }
}