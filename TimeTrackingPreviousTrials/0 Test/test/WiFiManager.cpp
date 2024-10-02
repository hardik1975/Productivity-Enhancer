#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password) 
    : ssid(ssid), password(password) {}

void WiFiManager::initWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi ..");
    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 20000) { // 20s timeout
        Serial.print('.');
        delay(1000);
    }
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Failed to connect to WiFi");
    } else {
        Serial.println(WiFi.localIP());
    }
}
