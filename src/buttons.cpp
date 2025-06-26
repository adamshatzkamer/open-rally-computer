// buttons.cpp - Universal button handling for M5Stack Core and Tough
#include <M5Stack.h>
#include "config.h"
#include "buttons.h"

// Variables to track button/touch states
bool previousState = false;
bool selectState = false;
bool nextState = false;

// Function to initialize buttons/touchscreen
void initButtons() {
#ifdef M5STACK_CORE
    // M5Stack Core buttons are initialized with M5.begin()
    Serial.println("M5Stack Core buttons initialized");
    
#elif defined(M5STACK_TOUGH)
    // M5Stack Tough touchscreen is initialized with M5.begin()
    Serial.println("M5Stack Tough touchscreen initialized");
    
    #ifdef USE_EXTERNAL_BUTTONS
        // Initialize external button pins
        pinMode(BUTTON_PREVIOUS_PIN, INPUT_PULLUP);
        pinMode(BUTTON_SELECT_PIN, INPUT_PULLUP);
        pinMode(BUTTON_NEXT_PIN, INPUT_PULLUP);
        Serial.println("External buttons initialized on M5Stack Tough");
    #endif
#endif
}

#ifdef M5STACK_TOUGH
// Function to check if a point is within a rectangular touch zone
bool isTouchInZone(int touchX, int touchY, int zoneX, int zoneY, int zoneW, int zoneH) {
    return (touchX >= zoneX && touchX <= (zoneX + zoneW) && 
            touchY >= zoneY && touchY <= (zoneY + zoneH));
}
#endif

// buttons.cpp - Universal button handling for M5Stack Core, Tough, and Blitz Buttons
#include <M5Stack.h>
#include "config.h"
#include "buttons.h"

#ifdef BLITZ_BUTTONS
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#endif

// Variables to track button/touch states
bool previousState = false;
bool selectState = false;
bool nextState = false;
bool upState = false;
bool downState = false;

// buttons.cpp - Universal button handling for M5Stack Core, Tough, and Blitz Buttons
#include <M5Stack.h>
#include "config.h"
#include "buttons.h"

#ifdef BLITZ_BUTTONS
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#endif

// Variables to track button/touch states
bool previousState = false;
bool selectState = false;
bool nextState = false;
bool upState = false;
bool downState = false;

// Function to initialize buttons/touchscreen/bluetooth
void initButtons() {
#ifdef M5STACK_CORE
    // M5Stack Core buttons are initialized with M5.begin()
    Serial.println("M5Stack Core buttons initialized");
    
#elif defined(M5STACK_TOUGH)
    // M5Stack Tough touchscreen is initialized with M5.begin()
    Serial.println("M5Stack Tough touchscreen initialized");
    
    #ifdef USE_EXTERNAL_BUTTONS
        // Initialize external button pins
        pinMode(BUTTON_PREVIOUS_PIN, INPUT_PULLUP);
        pinMode(BUTTON_SELECT_PIN, INPUT_PULLUP);
        pinMode(BUTTON_NEXT_PIN, INPUT_PULLUP);
        Serial.println("External buttons initialized on M5Stack Tough");
    #endif

#elif defined(BLITZ_BUTTONS)
    // Initialize Bluetooth Serial for Blitz Buttons
    SerialBT.begin("M5Stack_Rally_Computer"); // Bluetooth device name
    Serial.println("Bluetooth initialized for Blitz Buttons");
    Serial.println("Connect your Blitz Buttons to 'M5Stack_Rally_Computer'");

#elif defined(BLITZ_BUTTONS_WIRED)
    // Initialize GPIO pins for wired Blitz Buttons
    pinMode(BUTTON_PREVIOUS_PIN, INPUT_PULLUP);
    pinMode(BUTTON_SELECT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_NEXT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_UP_PIN, INPUT_PULLUP);
    pinMode(BUTTON_DOWN_PIN, INPUT_PULLUP);
    
    Serial.println("Wired Blitz Buttons initialized");
    Serial.println("GPIO pins configured for direct button connection");
    Serial.printf("Button pins: Prev=%d, Select=%d, Next=%d, Up=%d, Down=%d\n", 
                  BUTTON_PREVIOUS_PIN, BUTTON_SELECT_PIN, BUTTON_NEXT_PIN, 
                  BUTTON_UP_PIN, BUTTON_DOWN_PIN);
#endif
}

#ifdef M5STACK_TOUGH
// Function to check if a point is within a rectangular touch zone
bool isTouchInZone(int touchX, int touchY, int zoneX, int zoneY, int zoneW, int zoneH) {
    return (touchX >= zoneX && touchX <= (zoneX + zoneW) && 
            touchY >= zoneY && touchY <= (zoneY + zoneH));
}
#endif

#ifdef BLITZ_BUTTONS
// Function to handle Blitz Buttons Bluetooth commands
void handleBlitzButtons() {
    if (SerialBT.available()) {
        char command = SerialBT.read();
        
        // Handle keyboard commands from Blitz Buttons
        switch (command) {
            case BLITZ_CMD_PREVIOUS:
                Serial.println("Previous button pressed (Blitz Buttons)");
                // Add your navigation logic here
                break;
                
            case BLITZ_CMD_SELECT:
                Serial.println("Select button pressed (Blitz Buttons)");
                // Add your selection logic here
                break;
                
            case BLITZ_CMD_NEXT:
                Serial.println("Next button pressed (Blitz Buttons)");
                // Add your navigation logic here
                break;
                
            case BLITZ_CMD_UP:
                Serial.println("Up button pressed (Blitz Buttons)");
                // Add your up navigation logic here
                break;
                
            case BLITZ_CMD_DOWN:
                Serial.println("Down button pressed (Blitz Buttons)");
                // Add your down navigation logic here
                break;
                
            default:
                Serial.print("Unknown Blitz Button command: ");
                Serial.println((int)command);
                break;
        }
    }
    
    // Check Bluetooth connection status
    static unsigned long lastConnectionCheck = 0;
    if (millis() - lastConnectionCheck > 5000) { // Check every 5 seconds
        if (SerialBT.hasClient()) {
            // Connected - could show status on display
        } else {
            // Not connected - could show "waiting for Blitz Buttons" message
        }
        lastConnectionCheck = millis();
    }
}
#endif

#ifdef BLITZ_BUTTONS_WIRED
// Function to handle wired Blitz Buttons
void handleWiredBlitzButtons() {
    // Read current button states
    bool currentPrevious, currentSelect, currentNext, currentUp, currentDown;
    
    if (BLITZ_ACTIVE_LOW) {
        // Buttons pull LOW when pressed
        currentPrevious = digitalRead(BUTTON_PREVIOUS_PIN) == LOW;
        currentSelect = digitalRead(BUTTON_SELECT_PIN) == LOW;
        currentNext = digitalRead(BUTTON_NEXT_PIN) == LOW;
        currentUp = digitalRead(BUTTON_UP_PIN) == LOW;
        currentDown = digitalRead(BUTTON_DOWN_PIN) == LOW;
    } else {
        // Buttons pull HIGH when pressed
        currentPrevious = digitalRead(BUTTON_PREVIOUS_PIN) == HIGH;
        currentSelect = digitalRead(BUTTON_SELECT_PIN) == HIGH;
        currentNext = digitalRead(BUTTON_NEXT_PIN) == HIGH;
        currentUp = digitalRead(BUTTON_UP_PIN) == HIGH;
        currentDown = digitalRead(BUTTON_DOWN_PIN) == HIGH;
    }
    
    // Handle button press events (rising edge detection)
    if (currentPrevious && !previousState) {
        Serial.println("Previous button pressed (Wired Blitz Button)");
        // Add your navigation logic here
        // Example: navigate to previous screen/mode
    }
    
    if (currentSelect && !selectState) {
        Serial.println("Select button pressed (Wired Blitz Button)");
        // Add your selection logic here
        // Example: select current option or toggle display mode
    }
    
    if (currentNext && !nextState) {
        Serial.println("Next button pressed (Wired Blitz Button)");
        // Add your navigation logic here
        // Example: navigate to next screen/mode
    }
    
    if (currentUp && !upState) {
        Serial.println("Up button pressed (Wired Blitz Button)");
        // Add your up navigation logic here
        // Example: scroll up, increase value, etc.
    }
    
    if (currentDown && !downState) {
        Serial.println("Down button pressed (Wired Blitz Button)");
        // Add your down navigation logic here
        // Example: scroll down, decrease value, etc.
    }
    
    // Update button states
    previousState = currentPrevious;
    selectState = currentSelect;
    nextState = currentNext;
    upState = currentUp;
    downState = currentDown;
}
#endif

// Function to handle button presses (called from main loop)
void handleButtonPresses() {
    M5.update(); // Update M5Stack state
    
#ifdef M5STACK_CORE
    // Handle M5Stack Core built-in buttons
    if (M5.BtnA.wasPressed()) {
        Serial.println("Previous button pressed (Core Button A)");
        // Add your navigation logic here
    }
    
    if (M5.BtnB.wasPressed()) {
        Serial.println("Select button pressed (Core Button B)");
        // Add your selection logic here
    }
    
    if (M5.BtnC.wasPressed()) {
        Serial.println("Next button pressed (Core Button C)");
        // Add your navigation logic here
    }
    
#elif defined(M5STACK_TOUGH)
    bool touchHandled = false;
    
    #ifdef USE_EXTERNAL_BUTTONS
        // Handle external physical buttons on M5Stack Tough
        bool currentPrevious = digitalRead(BUTTON_PREVIOUS_PIN) == LOW;
        bool currentSelect = digitalRead(BUTTON_SELECT_PIN) == LOW;
        bool currentNext = digitalRead(BUTTON_NEXT_PIN) == LOW;
        
        if (currentPrevious && !previousState) {
            Serial.println("Previous button pressed (External Button)");
            touchHandled = true;
        }
        if (currentSelect && !selectState) {
            Serial.println("Select button pressed (External Button)");
            touchHandled = true;
        }
        if (currentNext && !nextState) {
            Serial.println("Next button pressed (External Button)");
            touchHandled = true;
        }
        
        previousState = currentPrevious;
        selectState = currentSelect;
        nextState = currentNext;
    #endif
    
    // Handle touchscreen (if no external buttons or as backup)
    if (!touchHandled && M5.Touch.ispressed()) {
        int touchX = M5.Touch.getPressPoint().x;
        int touchY = M5.Touch.getPressPoint().y;
        
        // Check Previous touch zone
        if (isTouchInZone(touchX, touchY, TOUCH_PREV_X, TOUCH_PREV_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT)) {
            if (!previousState) {
                Serial.println("Previous button touched (Touchscreen)");
                previousState = true;
            }
        }
        // Check Select touch zone
        else if (isTouchInZone(touchX, touchY, TOUCH_SELECT_X, TOUCH_SELECT_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT)) {
            if (!selectState) {
                Serial.println("Select button touched (Touchscreen)");
                selectState = true;
            }
        }
        // Check Next touch zone
        else if (isTouchInZone(touchX, touchY, TOUCH_NEXT_X, TOUCH_NEXT_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT)) {
            if (!nextState) {
                Serial.println("Next button touched (Touchscreen)");
                nextState = true;
            }
        }
        
        Serial.printf("Touch at: X=%d, Y=%d\n", touchX, touchY);
    } else {
        #ifndef USE_EXTERNAL_BUTTONS
        // Reset touch states when not touching (only if no external buttons)
        previousState = false;
        selectState = false;
        nextState = false;
        #endif
    }

#elif defined(BLITZ_BUTTONS)
    // Handle Blitz Buttons Bluetooth input
    handleBlitzButtons();

#elif defined(BLITZ_BUTTONS_WIRED)
    // Handle wired Blitz Buttons input
    handleWiredBlitzButtons();
#endif
}

// Function to read button states (alternative implementation)
void readButtons() {
    M5.update();
    
#ifdef M5STACK_CORE
    if (M5.BtnA.isPressed()) Serial.println("Button A held");
    if (M5.BtnB.isPressed()) Serial.println("Button B held");
    if (M5.BtnC.isPressed()) Serial.println("Button C held");
    
#elif defined(M5STACK_TOUGH)
    #ifdef USE_EXTERNAL_BUTTONS
        if (digitalRead(BUTTON_PREVIOUS_PIN) == LOW) Serial.println("External Previous held");
        if (digitalRead(BUTTON_SELECT_PIN) == LOW) Serial.println("External Select held");
        if (digitalRead(BUTTON_NEXT_PIN) == LOW) Serial.println("External Next held");
    #endif
    
    if (M5.Touch.ispressed()) {
        int touchX = M5.Touch.getPressPoint().x;
        int touchY = M5.Touch.getPressPoint().y;
        Serial.printf("Touch held at: X=%d, Y=%d\n", touchX, touchY);
    }
#endif
}