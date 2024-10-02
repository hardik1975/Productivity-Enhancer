#include "Arduino.h"
#include "tftDisplay.h"

const int radius = 60;
const int centerX = 160;
const int centerY = 120;

#define TFT_CS 4  
#define TFT_DC 21 
#define TFT_MOSI 2
#define TFT_CLK 19
#define TFT_RST 18
#define TFT_MISO 5 

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);


void tft_DisplaySetup() 
{
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);

  // Draw the constant outer circle
  tft.drawCircle(centerX, centerY, radius, ILI9341_WHITE);

  tft.setTextSize(1);
  tft.setTextColor(ILI9341_YELLOW);
  tft.print("Enter time in format Hour:Minute:Second");
  // tft.fillScreen()
}

void drawArcSegment(int x, int y, int start_angle, int end_angle, int r, uint16_t color) {
  for (int i = start_angle; i <= end_angle; i++) {
    float radians = i * PI / 180.0;
    int x1 = x + r * cos(radians);
    int y1 = y + r * sin(radians);
    tft.drawLine(x, y, x1, y1, color);
  }
}

