#ifndef MAINAPP_H
#define MAINAPP_H

#include "time.h"
#include "WiFiManager.h"
#include "TimeManager.h"

class MainApp {
public:
    MainApp(const char* ssid, const char* password, const char* ntpServer);
    void setup();
    void loop();
private:
    WiFiManager wifiManager;
    TimeManager timeManager;
    int i;
    unsigned long previousMillis;
    const long interval;
    unsigned long epochTime;
    unsigned long epochTime1;
};

#endif
