#include "appMain.h"

void appSetup()
{
  Serial.begin(115200);
  Serial.println("Enter time in format Hour:Minute:Second");
  tft_DisplaySetup();
}

void appLoop()
{
  /* ----------------- Takes user's input from Serial Monitor ----------------- */
  userInput();
  
  /* ---------- If User input values in right format, then run timer ---------- */
  runTimer();
}