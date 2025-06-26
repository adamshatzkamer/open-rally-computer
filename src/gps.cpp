#include <TinyGPSPlus.h>
#include <HardwareSerial.h>
#include "config.h"
#include "gps.h"

// Create an instance of the TinyGPSPlus object
TinyGPSPlus gps;

// Create a hardware serial instance for GPS
HardwareSerial gpsSerial(2);

// Function to initialize the GPS module
void initGPS() {
    gpsSerial.begin(9600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
    Serial.println("GPS initialized");
}

// Function to update GPS data (called in main loop)
void updateGPS() {
    while (gpsSerial.available() > 0) {
        gps.encode(gpsSerial.read());
    }
}

// Function to read GPS data
bool readGPS() {
    while (gpsSerial.available() > 0) {
        gps.encode(gpsSerial.read());
    }
    return gps.location.isUpdated();
}

// Function to get the current latitude
float getLatitude() {
    if (gps.location.isValid()) {
        return gps.location.lat();
    }
    return 0.0;
}

// Function to get the current longitude
float getLongitude() {
    if (gps.location.isValid()) {
        return gps.location.lng();
    }
    return 0.0;
}

// Function to get the current speed in km/h
float getSpeed() {
    if (gps.speed.isValid()) {
        return gps.speed.kmph();
    }
    return 0.0;
}

// Function to check if the GPS has a fix
bool hasFix() {
    return gps.location.isValid();
}