// Open Rally Computer - Universal Version
// Supports both M5Stack Core (built-in buttons) and M5Stack Tough (touchscreen + optional external buttons)
// Configure in config.h by uncommenting the appropriate #define

#include <M5Stack.h>
#include "config.h"
#include "display.h"
#include "gps.h"
#include "buttons.h"

void setup() {
    // Initialize M5Stack (this initializes display, buttons/touch, speaker, etc.)
    M5.begin();
    
    // Initialize serial for debugging
    Serial.begin(115200);
    Serial.println("=================================");
    Serial.println("Rally Computer Starting...");
    
#ifdef M5STACK_CORE
    Serial.println("Device: M5Stack Core");
    Serial.println("Input: Built-in buttons (A, B, C)");
#elif defined(M5STACK_TOUGH)
    Serial.println("Device: M5Stack Tough");
    #ifdef USE_EXTERNAL_BUTTONS
        Serial.println("Input: External buttons + Touchscreen");
    #else
        Serial.println("Input: Touchscreen only");
    #endif
#elif defined(BLITZ_BUTTONS)
    Serial.println("Device: M5Stack with Blitz Buttons");
    Serial.println("Input: Bluetooth HID (Professional Rally Buttons)");
    Serial.println("Connect Blitz Buttons to: M5Stack_Rally_Computer");
#elif defined(BLITZ_BUTTONS_WIRED)
    Serial.println("Device: M5Stack with Blitz Buttons (Wired)");
    Serial.println("Input: Direct GPIO (Professional Rally Buttons)");
    Serial.println("Buttons wired directly to M5Stack GPIO pins");
#endif
    
    Serial.println("=================================");
    
    // Initialize display
    initDisplay();
    
    // Initialize GPS
    initGPS();
    
    // Initialize buttons/touchscreen
    initButtons();
    
    Serial.println("Rally Computer Ready!");
}

void loop() {
    // Update GPS data
    updateGPS();
    
    // Handle button presses
    handleButtonPresses();
    
    // Update display with current data
    updateDisplay();
    
    // Add a small delay to avoid overwhelming the loop
    delay(100);
}