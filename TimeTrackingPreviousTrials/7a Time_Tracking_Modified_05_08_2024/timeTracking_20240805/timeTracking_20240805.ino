#include "time.h"

void setup() 
{
  initialSetup();
}

void loop() 
{ 

  //Takes user's input from Serial Monitor
  userInput();
  
  //If User input values in right format, then run timer
  runTimer();
  
}