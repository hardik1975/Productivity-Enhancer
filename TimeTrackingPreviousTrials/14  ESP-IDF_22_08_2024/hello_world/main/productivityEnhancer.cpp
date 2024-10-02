#include "Arduino.h"
#include "appMain.h"

// extern Adafruit_ILI9341 tft;

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

        // tft.begin();
        // tft.setRotation(3);
        // tft.fillScreen(ILI9341_BLACK);
        // tft.setFont(&FreeSans24pt7b);  // Set the font to FreeSans 24pt

        // tft.setTextColor(ILI9341_WHITE);
        // // tft.setTextSize(1);

        // int prevNum = -1; // Store the previous number to compare

        // for (int i = 0; i < 1000; i++) {
        //     if (i != prevNum) {
        //         // Clear only the digits that have changed
        //         tft.setTextColor(ILI9341_BLACK);
        //         tft.setCursor(10, 100);
        //         tft.print(prevNum);

        //         // Display the new number
        //         tft.setTextColor(ILI9341_WHITE);
        //         tft.setCursor(10, 100);
        //         tft.print(i);

        //         prevNum = i; // Update the previous number
        //     }

        //     delay(1000);
        // }

        // Draw the constant outer circle
        // tft.drawCircle(centerX, centerY, radius, ILI9341_WHITE);

        
        // tft.setTextSize(1);
        // tft.setTextColor(ILI9341_YELLOW);
        // tft.print("Enter time in format Hour:Minute:Second");
        // tft.fillScreen()

        // tft.print("Hello World");

        // tft.fillRect(10, 10, 100, 20, ILI9341_BLACK);
        // tft.setTextColor(ILI9341_WHITE);
        // tft.setTextSize(2);
        // tft.setCursor(10, 10); 

        // tft.print(timeString);

        appSetup();

        while(1)
        {
            appLoop();
        }
         
    }

}
