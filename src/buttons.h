#ifndef BUTTONS_H
#define BUTTONS_H

// Function declarations for button/touchscreen/Bluetooth management
void initButtons();
void handleButtonPresses();
void readButtons();

#ifdef M5STACK_TOUGH
bool isTouchInZone(int touchX, int touchY, int zoneX, int zoneY, int zoneW, int zoneH);
#endif

#ifdef BLITZ_BUTTONS
void handleBlitzButtons();
#endif

#ifdef BLITZ_BUTTONS_WIRED
void handleWiredBlitzButtons();
#endif

#endif // BUTTONS_H
