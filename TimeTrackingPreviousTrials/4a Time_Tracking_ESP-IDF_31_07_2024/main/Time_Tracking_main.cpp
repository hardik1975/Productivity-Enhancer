#include "Arduino.h"

#include "timeManager.h"
#include "connectWiFi.h"


int i = 0;

unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 1000;  // interval at which to blink (milliseconds)


/* ------------------------- instance for WiFi Class ------------------------ */
connectWifi connectWifi1("yo", "hardikhardik");


/* ------------------- instance for Time Management Class ------------------- */
timeManager t1("pool.ntp.org");


// Variable to save current epoch time
unsigned long epochTime; 
unsigned long epochTime1; 

extern "C"
{
    #include <stdio.h>
    #include <inttypes.h>
    #include "sdkconfig.h"
    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"
    #include "esp_chip_info.h"
    #include "esp_flash.h"

    void app_main(void)
    {
        printf("Hello world!\n");

        initArduino();
        Serial.begin(115200);
  
        connectWifi1.initWifi();

        t1.initTime();

        epochTime1 = t1.getTime();

        while(1) 
        {
            epochTime = t1.getTime();

            unsigned long currentMillis = millis();
            if (currentMillis < previousMillis) { // Detect overflow
                previousMillis = currentMillis; // Reset the previousMillis
            }

            if ((epochTime - epochTime1) == 10) {
                Serial.println("Bhaiya 10 second ho gye");
                epochTime1 = t1.getTime();
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



    }
}