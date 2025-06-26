#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

// Function declarations for utility functions
String formatGPSData(float latitude, float longitude, float speed);
void handleError(const char* errorMessage);

#endif // UTILS_H
