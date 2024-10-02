// counting on screen

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

// Variable to hold the last displayed time
String lastTime = "";

void setup() {
  // Initialize the serial monitor
  Serial.begin(115200);
  
  // Initialize the TFT display
  tft.begin();
  
  // Set the rotation of the display
  tft.setRotation(3);
  
  // Fill the screen with black color
  tft.fillScreen(ILI9341_BLACK);
  
  // Set text color and size
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
}

int i =0;

void loop() 
{
  mainLoop();

  // // void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

  // // tft.fillRect(10, 10, 100, 60, ILI9341_BLACK);
  // tft.fillRect(10, 10, 100, 20, ILI9341_BLACK);
  // tft.setTextColor(ILI9341_WHITE);
  // tft.setTextSize(2);
  // tft.setCursor(10, 10);

  // // for(int i = 0; i< 100; i++)
  // // {
  //   i ++;
  //   tft.print(i);
  //   delay(1000);
  // // }

  // // tft.print("DONE!");
  

}

void mainLoop()
{
  // Get the current time
  int hours = hour();
  int minutes = minute();
  int seconds = second();

  // Convert time to string
  String timeString = String(hours) + ":" + (minutes < 10 ? "0" : "") + String(minutes) + ":" + (seconds < 10 ? "0" : "") + String(seconds);

  // Only update if the time has changed
  if (timeString != lastTime) {
    // Clear the previous time by overwriting it with black
    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(10, 100);
    tft.print(lastTime);

    // Display the new time
    tft.setTextColor(ILI9341_WHITE);
    tft.setCursor(10, 100);
    tft.print(timeString);

    // Update lastTime
    lastTime = timeString;

    delay(16);
  }

  // Update every second
  delay(1000);
}

int hour() {
  return (millis() / 3600000) % 24;
}

int minute() {
  return (millis() / 60000) % 60;
}

int second() {
  return (millis() / 1000) % 60;
}
