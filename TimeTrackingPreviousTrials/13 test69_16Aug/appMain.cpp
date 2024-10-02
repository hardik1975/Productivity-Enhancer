#include "appMain.h"

void appSetup()
{
  Serial.begin(115200);

  userEnterTimePrompt();  // Print the Time Format

  tft_DisplaySetup();
}

void appLoop()
{
  /* ----------------- Takes user's input from Serial Monitor ----------------- */
  userInput();
  
  /* ---------- If User input values in right format, then run timer ---------- */
  runTimer();
}