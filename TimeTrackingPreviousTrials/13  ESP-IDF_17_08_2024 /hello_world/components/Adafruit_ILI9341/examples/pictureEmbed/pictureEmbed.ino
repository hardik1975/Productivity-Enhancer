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

#include "SPI.h"
#include <Adafruit_ILI9341.h>
#include "dragon.h"

// For the Adafruit shield, these are the default.
//#define TFT_DC 9
//#define TFT_CS 10

// 
#define TFT_CS 4
#define TFT_DC 21
#define TFT_MOSI 2
#define TFT_CLK 19
#define TFT_RST 18
#define TFT_MISO 25

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

void setup() {
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
}

void loop(void) 
{
  // for(uint8_t r=0; r<4; r++) 
    
    // for(uint8_t j=0; j<20; j++) 
    // {
      tft.drawRGBBitmap( 0,0, (uint16_t *)dragonBitmap, DRAGON_WIDTH, DRAGON_HEIGHT);

      
      delay(1); // Allow ESP8266 to handle watchdog & WiFi stuff
    // }
    delay(3000);

}
