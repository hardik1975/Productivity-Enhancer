unsigned long totalSeconds;
unsigned long remainingTime;

// unsigned long previousMillis = 0; // Store the last time update
// const long interval = 1000; // Interval for 1 second


// Convert total time into seconds
unsigned long totalTime(int hours, int min, int sec)
{
  totalSeconds = hours * 3600 + min * 60 + sec;
  return totalSeconds;
}


// void loop() 
// {
//   unsigned long currentMillis = millis();
//   if (currentMillis - previousMillis >= interval) {
//     previousMillis = currentMillis;

//     if (totalSeconds > 0) {
//       totalSeconds--;
//       printTime(totalSeconds);
//     } else {
//       Serial.println("Time's up!");
//     }
//   }
// }

void printTime(unsigned long totalSeconds) {
  int hours = totalSeconds / 3600;
  int minutes = (totalSeconds % 3600) / 60;
  int seconds = totalSeconds % 60;

  Serial.print("Hour : Min : Sec - ");
  Serial.print(hours);
  Serial.print(" : ");
  Serial.print(minutes);
  Serial.print(" : ");
  Serial.println(seconds);
}
