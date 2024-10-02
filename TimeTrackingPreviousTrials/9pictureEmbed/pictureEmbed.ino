// ILI9341 example with embedded color bitmaps in sketch.
// WILL NOT FIT ON ARDUINO UNO OR OTHER AVR BOARDS;
// uses large bitmap image stored in array!

// Options for converting images to the format used here include:
//   http://www.rinkydinkelectronics.com/t_imageconverter565.php
// or
//  GIMP (https://www.gimp.org/) as follows:
//    1. File -> Export As
//    2. In Export Image dialog, use 'C source code (*.c)' as filetype.
//    3. Press export to get the export options dialog.
//    4. Type the desired variable name into the 'prefixed name' box.
//    5. Uncheck 'GLIB types (guint8*)'
//    6. Check 'Save as RGB565 (16-bit)'
//    7. Press export to save your image.

//  Assuming 'image_name' was typed in the 'prefixed name' box of step 4,
//  you can have to include the c file, then using the image can be done with:
//    tft.drawRGBBitmap(0, 0, image_name.pixel_data, image_name.width, image_name.height);
//  See also https://forum.pjrc.com/threads/35575-Export-for-ILI9341_t3-with-GIMP

// #include "test.h"
// #include "test1.c"
#include "untitled.c"
#include "SPI.h"
#include <Adafruit_ILI9341.h>

// For the Adafruit shield, these are the default.
//#define TFT_DC 9
//#define TFT_CS 10

// 
#define TFT_CS 4  
#define TFT_DC 21 
#define TFT_MOSI 2
#define TFT_CLK 19
#define TFT_RST 18
#define TFT_MISO 5 

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
}

void loop(void) 
{
  // for(uint8_t r=0; r<4; r++) 
    
    // for(uint8_t j=0; j<20; j++) 
    // {
      // tft.drawRGBBitmap(
      //   0,0,
      //   // (uint16_t *)dragonBitmap,
      //   (uint16_t *)testVariable,
      //   width, height);

      tft.drawRGBBitmap(0, 0, (uint16_t *)gimp_image.pixel_data, gimp_image.width, gimp_image.height);

      Serial.println(gimp_image.width);
      Serial.println(gimp_image.height);

      // tft.drawRGBBitmap(0, 0, (uint16_t *)testVariable.pixel_data, testVariable.width, testVariable.height);

      // Serial.println(testVariable.width);
      // Serial.println(testVariable.height);

      // tft.writeRect(0, 0, image_name.width, image_name.height, (uint16_t*)(image_name.pixel_data));
      delay(1); // Allow ESP8266 to handle watchdog & WiFi stuff
    // }
    delay(3000);

    // tft.fillScreen(ILI9341_BLACK);

    // while(1)
    // {
      
    //   unsigned long start = micros();
    //   tft.setCursor(0, 0);
    //   tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(4);
    //   tft.println("Hello World!");
    //   tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
    //   tft.println(1234.56);
    //   tft.setTextColor(ILI9341_RED);    tft.setTextSize(3);
    //   tft.println(0xDEADBEEF, HEX);
    //   tft.println();
    //   tft.setTextColor(ILI9341_GREEN);
    //   tft.setTextSize(5);
    //   tft.println("Groop");
    //   tft.setTextSize(2);
    //   tft.println("I implore thee,");
    //   tft.setTextSize(1);
    //   tft.println("my foonting turlingdromes.");
    //   tft.println("And hooptiously drangle me");
    //   tft.println("with crinkly bindlewurdles,");
    //   tft.println("Or I will rend thee");
    //   tft.println("in the gobberwarts");
    //   tft.println("with my blurglecruncheon,");
    //   tft.println("see if I don't!");

    //   // for (int i = 0; i < 100; i++)
    //   // {
    //   //   // tft.fillScreen(ILI9341_BLACK);
    //   //   clearScreen();
    //   //   tft.setTextColor(ILI9341_BLUE);  tft.setTextSize(4);
    //   //   //  tft.setScrollMargins(1, 1);
    //   //   // tft.setCursor(0, 0);
    //   //   tft.println("Time :");
    //   //   tft.println(i);
    //   // }
    // }

    // delay(3000);

}

void clearScreen()
{
  tft.fillScreen(0); 

  tft.setCursor(0, 0);
  // tft.setTextColor(65535);  
}
