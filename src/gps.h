#ifndef GPS_H
#define GPS_H

// Function declarations for GPS management
void initGPS();
void updateGPS();
bool readGPS();
float getLatitude();
float getLongitude();
float getSpeed();
bool hasFix();

#endif // GPS_H
