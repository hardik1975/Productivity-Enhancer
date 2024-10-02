#ifndef TIME_H
#define TIME_H

#include "tftDisplay.h"

extern TFT_eSPI tft;       // Invoke custom library

bool parseTime(String input);

void userInput();
void runTimer();

#endif