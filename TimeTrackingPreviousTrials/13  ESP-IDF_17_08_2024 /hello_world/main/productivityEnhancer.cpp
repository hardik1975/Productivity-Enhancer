// #include "Arduino.h"
// #include "appMain.h"

// extern Adafruit_ILI9341 tft;

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

//         tft.begin();
//         tft.setRotation(3);
//         tft.fillScreen(ILI9341_BLACK);

//         const int radius = 60;
//         const int centerX = 160;
//         const int centerY = 120;


//         // Draw the constant outer circle
//         // tft.drawCircle(centerX, centerY, radius, ILI9341_WHITE);

//         // for(int i = 100; i>=0; i--) 
//         while(1){
//         for(int i = 0; i<=100; i++)
//         {
//             tft.drawCircle(centerX, centerY, i, ILI9341_WHITE);
//             delay(5);
//         }
//         tft.fillScreen(ILI9341_BLACK);
//         for(int i = 100; i>=0; i--)
//         {
//             tft.drawCircle(centerX, centerY, i, ILI9341_WHITE);
//             delay(5);
//         }
//         }

//         // tft.setTextSize(1);
//         // tft.setTextColor(ILI9341_YELLOW);
//         // tft.print("Enter time in format Hour:Minute:Second");
//         // tft.fillScreen()

//         tft.print("Hello World");

//         // tft.fillRect(10, 10, 100, 20, ILI9341_BLACK);
//         // tft.setTextColor(ILI9341_WHITE);
//         // tft.setTextSize(2);
//         // tft.setCursor(10, 10); 

//         // tft.print(timeString);

//         // appSetup();

//         // while(1)
//         // {
//         //     appLoop();
//         // }
         
//     }

// }

#include "Arduino.h"
#include "appMain.h"

extern Adafruit_ILI9341 tft;

// Helper function to blend colors
uint16_t blendColors(uint16_t bg, uint16_t fg, float alpha) {
    uint8_t fgR = (fg >> 11) & 0x1F;
    uint8_t fgG = (fg >> 5) & 0x3F;
    uint8_t fgB = fg & 0x1F;
    uint8_t bgR = (bg >> 11) & 0x1F;
    uint8_t bgG = (bg >> 5) & 0x3F;
    uint8_t bgB = bg & 0x1F;

    uint8_t r = fgR * alpha + bgR * (1 - alpha);
    uint8_t g = fgG * alpha + bgG * (1 - alpha);
    uint8_t b = fgB * alpha + bgB * (1 - alpha);

    return ((r & 0x1F) << 11) | ((g & 0x3F) << 5) | (b & 0x1F);
}

// Wu's algorithm for anti-aliased circle
void drawWuCircle(int32_t x0, int32_t y0, int32_t radius, uint16_t color) {
    int x = radius;
    int y = 0;
    int decisionOver2 = 1 - x;
    uint16_t bgColor = ILI9341_BLACK;  // Assuming black background

    while (y <= x) {
        float alpha = (float)(x * x + y * y - radius * radius) / (x * x + y * y);
        if (alpha < 0) alpha = 0;
        if (alpha > 1) alpha = 1;
        uint16_t blendedColor = blendColors(bgColor, color, 1 - alpha);

        tft.drawPixel(x0 + x, y0 + y, blendedColor);
        tft.drawPixel(x0 - x, y0 + y, blendedColor);
        tft.drawPixel(x0 + x, y0 - y, blendedColor);
        tft.drawPixel(x0 - x, y0 - y, blendedColor);
        tft.drawPixel(x0 + y, y0 + x, blendedColor);
        tft.drawPixel(x0 - y, y0 + x, blendedColor);
        tft.drawPixel(x0 + y, y0 - x, blendedColor);
        tft.drawPixel(x0 - y, y0 - x, blendedColor);

        y++;
        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;
        }
    }
}

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

        tft.begin();
        tft.setRotation(3);
        tft.fillScreen(ILI9341_BLACK);

        const int radius = 60;
        const int centerX = 160;
        const int centerY = 120;

        while(1){
        for(int i = 0; i<=100; i++)
        {
            drawWuCircle(centerX, centerY, i, ILI9341_WHITE);
            delay(5);
        }
        tft.fillScreen(ILI9341_BLACK);
        for(int i = 100; i>=0; i--)
        {
            drawWuCircle(centerX, centerY, i, ILI9341_WHITE);
            delay(5);
        }
        }

        tft.print("Hello World");
    }
}