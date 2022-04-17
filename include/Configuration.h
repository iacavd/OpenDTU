#pragma once

#include <Arduino.h>

#define CONFIG_FILENAME "/config.bin"
#define CONFIG_VERSION 0x00010000 // 0.1.0

#define WIFI_MAX_SSID_STRLEN 31
#define WIFI_MAX_PASSWORD_STRLEN 31
#define WIFI_MAX_HOSTNAME_STRLEN 31

struct CONFIG_T {
    uint32_t Cfg_Version;
    uint Cfg_SaveCount;

    char WiFi_Ssid[WIFI_MAX_SSID_STRLEN + 1];
    char WiFi_Password[WIFI_MAX_PASSWORD_STRLEN + 1];
    byte WiFi_Ip[4];
    byte WiFi_Netmask[4];
    byte WiFi_Gateway[4];
    byte WiFi_Dns1[4];
    byte WiFi_Dns2[4];
    bool WiFi_Dhcp;
    char WiFi_Hostname[WIFI_MAX_HOSTNAME_STRLEN + 1];
};

class ConfigurationClass {
public:
    void init();
    bool read();
    bool write();
    void migrate();
    CONFIG_T& get();
};

extern ConfigurationClass Configuration;