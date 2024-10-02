#pragma once

#include "Arduino.h"
#include <WiFi.h>

class connectWifi
{
  private:
    const char* ssid;
    const char* password;

  public:

    /**
     * @brief Constructor to store users Wifi & Password.
     *
     * @param ssid     : User's SSID
     * @param password : User's Password
     *
     * @see connectWifi::connectWifi()
     */
    connectWifi(const char* ssid, const char* password); 

    /**
     * @brief Function to connect with stored Wifi Credentials. 
     *
     * @return true if connected to WiFi, false otherwise.
     */
    bool initWifi();

};