#ifndef CONNECTWIFI_H
#define CONNECTWIFI_H

#include <WiFi.h>

class connectWifi
{
  private:
    const char* ssid;
    const char* password;

  public:
    connectWifi(const char* ssid, const char* password); 

    void initWifi();

};


#endif