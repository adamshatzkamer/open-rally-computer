// This file contains utility functions that support various operations within the project, such as data formatting and error handling.

#include "config.h"
#include "utils.h"

// Function to format GPS data for display
String formatGPSData(float latitude, float longitude, float speed) {
    String formattedData = "Lat: " + String(latitude, 6) + " Lon: " + String(longitude, 6) + " Spd: " + String(speed) + " km/h";
    return formattedData;
}

// Function to handle errors and display messages
void handleError(const char* errorMessage) {
    Serial.println(errorMessage);
    // Additional error handling logic can be added here
}