#include "Arduino.h"
#include "time.h"
#include "tftDisplay.h"

extern Adafruit_ILI9341 tft;

bool timerRunning = false;

unsigned long totalSeconds;
unsigned long startTime;


void userInput()
{
  if (Serial.available() > 0) 
  {
    String input = Serial.readStringUntil('\n');
    if (parseTime(input)) 
    {
      startTime = millis();
      timerRunning = true;
    } 
    else 
    {
      Serial.println("Invalid format. Please enter time in format Hour:Minute:Second and ensure it's within a reasonable range.");
      tft.print("Invalid format. Please enter time in format Hour:Minute:Second and ensure it's within a reasonable range.");
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

    if (currentTime >= startTime) {
      elapsedTime = (currentTime - startTime) / 1000;
    } else {
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

      tft.fillRect(10, 10, 100, 20, ILI9341_BLACK);
      tft.setTextColor(ILI9341_WHITE);
      tft.setTextSize(2);
      tft.setCursor(10, 10); 
      tft.print(seconds);

      delay(1000); // Update every second
    } 
    else 
    {
      Serial.println("Time's up!");
      tft.fillRect(10, 10, 100, 20, ILI9341_BLACK);
      tft.setTextColor(ILI9341_WHITE);
      tft.setTextSize(2);
      tft.setCursor(10, 10);
      tft.print("Time's up!");
      timerRunning = false;
    }
  }
}