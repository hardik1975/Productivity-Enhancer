unsigned long previousMillis = 0; // Store the last time update
const long interval = 1000; // Interval for 1 second

// Configurable countdown time
int countdownHours = 3;
int countdownMinutes = 0;
int countdownSeconds = 0;

// Convert total time into seconds
unsigned long totalSeconds = countdownHours * 3600 + countdownMinutes * 60 + countdownSeconds;

void setup() {
  Serial.begin(9600);
  printTime(totalSeconds);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (totalSeconds > 0) {
      totalSeconds--;
      printTime(totalSeconds);
    } else {
      Serial.println("Time's up!");
    }
  }
}

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
