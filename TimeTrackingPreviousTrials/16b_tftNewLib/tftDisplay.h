#ifndef TFTDISPLAY_H
#define TFTDISPLAY_H

#include "Arduino.h"
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include "Free_Fonts.h"

// TFT_eSPI tft = TFT_eSPI();        // Invoke custom library

void tft_DisplaySetup();

#endif