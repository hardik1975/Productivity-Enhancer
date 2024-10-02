#include "Arduino.h"
#include "time.h"

bool timerRunning = false;
unsigned long totalSeconds;
unsigned long startTime;

unsigned int prevHours = -1;
unsigned int prevMinutes = -1;
unsigned int prevSeconds = -1;

int xpos = 0;
int ypos = 85; // Top left corner ot clock text, about half way down
bool sw = 1;
byte omm = 99, oss = 99;
byte xcolon = 0, xsecs = 0;

void userInput()
{
  if (Serial.available() > 0) 
  {
    Serial.println("Serial Recieved");

    String input = Serial.readStringUntil('\n');
    if (parseTime(input)) 
    {
      tft.fillScreen(TFT_BLACK);
      tft.setTextSize(1);
      tft.setTextColor(TFT_YELLOW, TFT_BLACK);

      startTime = millis();
      timerRunning = true;
    } 
    else 
    {
      Serial.println("Invalid format. Please enter time in format Hour:Minute:Second.");
      tft.fillScreen(TFT_BLACK);
      tft.print("Invalid format.");
    }
  }
}

bool parseTime(String input) 
{
  int firstColon = input.indexOf(':');
  int secondColon = input.indexOf(':', firstColon + 1);

  if (firstColon == -1 || secondColon == -1) return false;

  String hourStr = input.substring(0, firstColon);
  String minuteStr = input.substring(firstColon + 1, secondColon);
  String secondStr = input.substring(secondColon + 1);

  int hours = hourStr.toInt();
  int minutes = minuteStr.toInt();
  int seconds = secondStr.toInt();

  if (hours < 0 || minutes < 0 || minutes >= 60 || seconds < 0 || seconds >= 60) return false;

  // Check for overflow by calculating total seconds and ensuring it's within the range of unsigned long
  unsigned long tempTotalSeconds = hours * 3600 + minutes * 60 + seconds;
  if (tempTotalSeconds > ULONG_MAX / 1000) return false; // Overflow check

  totalSeconds = tempTotalSeconds;
  return true;
}

void runTimer()
{
  if (timerRunning) 
  {
    unsigned long currentTime = millis();
    unsigned long elapsedTime;

    if (currentTime >= startTime) 
    {
      elapsedTime = (currentTime - startTime) / 1000;
    } 
    else 
    {
      elapsedTime = ((ULONG_MAX - startTime) + currentTime + 1) / 1000; // Handle millis() overflow
    }

    if (elapsedTime <= totalSeconds) 
    {
      unsigned long remainingSeconds = totalSeconds - elapsedTime;
      unsigned int hours = remainingSeconds / 3600;
      unsigned int minutes = (remainingSeconds % 3600) / 60;
      unsigned int seconds = remainingSeconds % 60;

      Serial.print("Remaining time: ");
      Serial.print(hours);
      Serial.print(":");
      if (minutes < 10) Serial.print("0");
      Serial.print(minutes);
      Serial.print(":");
      if (seconds < 10) Serial.print("0");
      Serial.println(seconds);

      // if (prevHours != hours)
      // {
      //   tft.setTextColor(ILI9341_BLACK);
      //   tft.setCursor(10, 10);
      //   tft.setTextSize(3);
      //   // tft.print(prevHours);
      //   tft.drawNumber(prevHours, xpos, ypos, 8);

      //   // Display the new number
      //   tft.setTextColor(ILI9341_WHITE);
      //   tft.setCursor(10, 10);
      //   tft.print(hours);
      //   if(hours == 0)
      //   {
      //     tft.print(hours);
      //   }
      //   tft.print(":");

      //   prevHours = hours; // Update the previous number
      // }
      
      // if (prevMinutes != minutes)
      // {
      //   tft.setTextColor(ILI9341_BLACK);
      //   tft.setCursor(60, 10);
      //   tft.setTextSize(3);
      //   if (prevMinutes < 10) tft.print("0");
      //   tft.print(prevMinutes);

      //   // Display the new number
      //   tft.setTextColor(ILI9341_WHITE);
      //   tft.setCursor(60, 10);
      //   if (minutes < 10) tft.print("0");
      //   tft.print(minutes);
        
      //   tft.print(":");

      //   prevMinutes = minutes; // Update the previous number
      // }

      // if (prevSeconds != seconds)
      // {
      //   tft.setTextColor(ILI9341_BLACK);
      //   tft.setCursor(110, 10);
      //   tft.setTextSize(3);
      //   if (prevSeconds < 10) tft.print("0");
      //   // tft.print(prevSeconds);
      //   tft.drawNumber(prevSeconds, xpos, ypos, 8);

      //   // Display the new number
      //   tft.setTextColor(ILI9341_WHITE);
      //   tft.setCursor(110, 10);
      //   if (seconds < 10) tft.print("0");
      //   tft.print(seconds);

      //   prevSeconds = seconds; // Update the previous number
      // }

      int xpos = 0;
      int ypos = 85; // Top left corner ot clock text, about half way down
      int ysecs = ypos + 24;

      if (prevMinutes != minutes) // Redraw hours and minutes time every minute
      { 
        prevMinutes = minutes;
        // Draw hours and minutes
        if (hours < 10) xpos += tft.drawChar('0', xpos, ypos, 8); // Add hours leading zero for 24 hr clock
        xpos += tft.drawNumber(hours, xpos, ypos, 8);             // Draw hours
        xcolon = xpos; // Save colon coord for later to flash on/off later
        xpos += tft.drawChar(':', xpos, ypos - 8, 8);
        if (minutes < 10) xpos += tft.drawChar('0', xpos, ypos, 8); // Add minutes leading zero
        xpos += tft.drawNumber(minutes, xpos, ypos, 8);             // Draw minutes
        xsecs = xpos; // Sae seconds 'x' position for later display updates
      }

      if (prevSeconds != seconds) // Redraw seconds time every second
      { 
        prevSeconds = seconds;
        xpos = xsecs;

        if (seconds % 2) { // Flash the colons on/off
          tft.setTextColor(0x39C4, TFT_BLACK);        // Set colour to grey to dim colon
          tft.drawChar(':', xcolon, ypos - 8, 8);     // Hour:minute colon
          xpos += tft.drawChar(':', xsecs, ysecs, 6); // Seconds colon
          tft.setTextColor(TFT_YELLOW, TFT_BLACK);    // Set colour back to yellow
        }
        else {
          tft.drawChar(':', xcolon, ypos - 8, 8);     // Hour:minute colon
          xpos += tft.drawChar(':', xsecs, ysecs, 6); // Seconds colon
        }

        //Draw seconds
        if (seconds < 10) xpos += tft.drawChar('0', xpos, ysecs, 6); // Add leading zero
        tft.drawNumber(seconds, xpos, ysecs, 6);                     // Draw seconds
      }

    } 

    else 
    {
      tft.fillScreen(TFT_BLACK);
      
      // tft.setTextColor(ILI9341_WHITE);
      // tft.setTextSize(2);
      // tft.print("Time's up!");

      tft.setFreeFont(FSB24);
      for(int i=0; i<6; i++)
      {
        tft.setCursor(xpos, ypos);
        tft.println("Time Up");
        delay(500);
        tft.fillScreen(TFT_BLACK); 
        delay(500);
      }
      tft.fillScreen(TFT_BLACK);

      timerRunning = false;
    }
  }
}