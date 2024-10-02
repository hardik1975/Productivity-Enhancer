// ChatGPT

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
// #include <SPI.h>
#include <Fonts/FreeSans24pt7b.h>

#define TFT_CS 4  
#define TFT_DC 21 
#define TFT_MOSI 2
#define TFT_CLK 19
#define TFT_RST 18
#define TFT_MISO 5 

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);


int count = 0;

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  
  tft.setFont(&FreeSans24pt7b);  // Set the font to FreeSans 24pt
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(10, 60);  // Adjusted cursor position to fit the larger font
}

void loop() {
  // Clear the area that might be occupied by the largest possible number ("9999")
  tft.fillRect(10, 20, 240, 60, ILI9341_BLACK);
  
  // Print the current count
  tft.setCursor(10, 60);
  tft.print(count);
  
  // Increment the count
  count++;
  
  // Delay for a short time to create a smoother transition
  delay(1000);  // Update every 100ms for a smoother transition
}
