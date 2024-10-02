#include "MainApp.h"
#include <Arduino.h>

MainApp::MainApp(const char* ssid, const char* password, const char* ntpServer)
    : wifiManager(ssid, password), timeManager(ntpServer), i(0), previousMillis(0), interval(1000), epochTime(0), epochTime1(0) {}

void MainApp::setup() {
    Serial.begin(115200);
    wifiManager.initWiFi();
    timeManager.initTime();
    epochTime1 = timeManager.getTime();
}

void MainApp::loop() {
    epochTime = timeManager.getTime();
    unsigned long currentMillis = millis();
    if (currentMillis < previousMillis) {
        previousMillis = currentMillis;
    }
    if ((epochTime - epochTime1) == 10) {
        Serial.println("Bhaiya 10 second ho gye");
        epochTime1 = timeManager.getTime();
        i = 0;
    } else {
        if (currentMillis - previousMillis >= interval) {
            i++;
            Serial.println(i);
            previousMillis = currentMillis;
        }
    }
}
