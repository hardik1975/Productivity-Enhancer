// Lakshya ka Circle Animation code

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

#define TFT_CS 4  
#define TFT_DC 21 
#define TFT_MOSI 2
#define TFT_CLK 19
#define TFT_RST 18
#define TFT_MISO 5 

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

const int totalTime = 3600;
unsigned long startTime;
unsigned long elapsedTime;
int remainingTime;
int lastAngle = 0;

const int radius = 100;
const int centerX = 160;
const int centerY = 120;

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  
  // Draw the constant outer circle
  tft.drawCircle(centerX, centerY, radius, ILI9341_WHITE);
  
  startTime = millis();
}

void drawArcSegment(int x, int y, int start_angle, int end_angle, int r, uint16_t color) {
  for (int i = start_angle; i <= end_angle; i++) {
    float radians = i * PI / 180.0;
    int x1 = x + r * cos(radians);
    int y1 = y + r * sin(radians);
    tft.drawLine(x, y, x1, y1, color);
  }
}

void loop() 
{
  elapsedTime = (millis() - startTime) / 1000;
  remainingTime = totalTime - elapsedTime;
  
  if (remainingTime < 0) remainingTime = 0;

  int angle = map(totalTime - remainingTime, 0, totalTime, 0, 360);
  
  if (angle > lastAngle) {
    // Only draw the new segment
    drawArcSegment(centerX, centerY, lastAngle, angle, radius - 1, ILI9341_CYAN);
    
    // Update time display only if it has changed
    if (remainingTime != (totalTime - elapsedTime + 1)) {
      tft.fillRect(10, 10, 100, 20, ILI9341_BLACK);
      tft.setTextColor(ILI9341_WHITE);
      tft.setTextSize(2);
      tft.setCursor(10, 10);
      
      if (remainingTime > 0) {
        tft.print(remainingTime);
      } else {
        tft.print("DONE!");
      }
    }
    
    lastAngle = angle;
  }

  delay(16); // Approx. 60 FPS
}