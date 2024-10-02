#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

#include "Free_Fonts.h"

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

int xpos = 0;
int ypos = 85; // Top left corner ot clock text, about half way down

bool sw = 1;

void setup() 
{
  Serial.begin(115200);
  tft.init();
  tft.setRotation(3);
  
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
}

void loop()
{
  for(int i=20; i>0; i--)
  {
     if(i<10 && sw)
     {
        // tft.drawNumber(0, xpos, ypos, 8);
        xpos += tft.drawChar('0', xpos, ypos, 8);
        sw = 0;
     }
     else if(i == 20)
     {
      xpos = 0;
      sw = 1;
     }

    tft.drawNumber(i, xpos, ypos, 8);

    delay(500);
  }

  tft.setCursor(xpos, ypos);
  tft.setFreeFont(FSB24);
  tft.println("Time Up");
  delay(500);
  tft.fillScreen(TFT_BLACK); 
  delay(500);
  
}
