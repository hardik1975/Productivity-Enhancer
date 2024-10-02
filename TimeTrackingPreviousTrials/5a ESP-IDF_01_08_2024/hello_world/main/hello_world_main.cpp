#include "Arduino.h"
#include "timeManager.h"
#include "connectWifi.h"

    int i = 0;

    unsigned long previousMillis = 0;  // will store last time LED was updated
    const long interval = 1000;  // interval at which to blink (milliseconds)

    /* ------------------------- instance for WiFi Class ------------------------ */
    connectWifi connectWifi("yo", "hardikhardik");

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
        pinMode(2, OUTPUT);
        Serial.begin(115200);

        if(connectWifi.initWifi())
        {
            digitalWrite(2, HIGH);   
        }

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

            vTaskDelay(1);
        }

    }
}


// #include <WiFi.h>
// #include "time.h"

// int i = 0;

// unsigned long previousMillis = 0;  // will store last time LED was updated
// const long interval = 1000;  // interval at which to blink (milliseconds)

// // Replace with your network credentials
// const char* ssid = "yo";
// const char* password = "hardikhardik";

// // NTP server to request epoch time
// const char* ntpServer = "pool.ntp.org";

// // Variable to save current epoch time
// unsigned long epochTime; 
// unsigned long epochTime1; 

// // Function that gets current epoch time
// unsigned long getTime() {
//   time_t now;
//   struct tm timeinfo;
//   if (!getLocalTime(&timeinfo)) {
//     //Serial.println("Failed to obtain time");
//     return 0;
//   }
//   time(&now);
//   if (now < 1000000000) { // Check if the epoch time is realistic
//     return 0;
//   }
//   return now;
// }

// // Initialize WiFi
// void initWiFi() {
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi ..");
//   unsigned long startAttemptTime = millis();
//   while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 20000) { // 20s timeout
//     Serial.print('.');
//     delay(1000);
//   }
//   if (WiFi.status() != WL_CONNECTED) {
//     Serial.println("Failed to connect to WiFi");
//     // Handle error or retry logic
//   } else {
//     Serial.println(WiFi.localIP());
//   }
// }

// extern "C"
// {
//     #include <stdio.h>
//     #include <inttypes.h>
//     #include "sdkconfig.h"
//     #include "freertos/FreeRTOS.h"
//     #include "freertos/task.h"
//     #include "esp_chip_info.h"
//     #include "esp_flash.h"

//     void app_main(void)
//     {
//         printf("Hello world!\n");

//         initArduino();

//         Serial.begin(115200);

//         initWiFi();
//         configTime(0, 0, ntpServer);

//         epochTime1 = getTime();

//         while(1) 
//         {
//             epochTime = getTime();

//             unsigned long currentMillis = millis();
//             if (currentMillis < previousMillis) { // Detect overflow
//                 previousMillis = currentMillis; // Reset the previousMillis
//             }

//             if ((epochTime - epochTime1) == 10) {
//                 Serial.println("Bhaiya 10 second ho gye");
//                 epochTime1 = getTime();
//                 i = 0;
//             } else {
//                 if (currentMillis - previousMillis >= interval) {
//                 i++;
//                 Serial.println(i);

//                 // save the last time you blinked the LED
//                 previousMillis = currentMillis;
//                 }

//             }

//             vTaskDelay(1);
//         }
//     }
// }