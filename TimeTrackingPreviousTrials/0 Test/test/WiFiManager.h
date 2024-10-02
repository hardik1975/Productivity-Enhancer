#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <WiFi.h>

class WiFiManager {
public:
    WiFiManager(const char* ssid, const char* password);
    void initWiFi();
private:
    const char* ssid;
    const char* password;
};

#endif
