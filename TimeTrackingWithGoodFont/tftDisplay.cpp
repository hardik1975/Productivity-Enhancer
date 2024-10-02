#include "tftDisplay.h"

TFT_eSPI tft = TFT_eSPI();        // Invoke custom library

void tft_DisplaySetup() 
{
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
}
