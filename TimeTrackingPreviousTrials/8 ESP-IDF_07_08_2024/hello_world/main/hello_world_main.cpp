#include "Arduino.h"
#include "time.h"

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

        initialSetup();

        while(1)
        {
            /* ----------------- Takes user's input from Serial Monitor ----------------- */
            userInput();
            
            /* ---------- If User input values in right format, then run timer ---------- */
            runTimer();
        }
         
    }

}