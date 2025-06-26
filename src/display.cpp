#include <M5Stack.h>
#include "config.h"
#include "display.h"
#include "gps.h"

// Function to initialize the display
void initDisplay() {
    M5.Lcd.begin();
    M5.Lcd.setRotation(1); // Landscape orientation
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 10);
    
#ifdef M5STACK_CORE
    M5.Lcd.println("Rally Computer");
    M5.Lcd.println("M5Stack Core");
#elif defined(M5STACK_TOUGH)
    M5.Lcd.println("Rally Computer");
    M5.Lcd.println("M5Stack Tough");
    #ifdef USE_EXTERNAL_BUTTONS
        M5.Lcd.setTextSize(1);
        M5.Lcd.println("w/ External Buttons");
    #endif
#elif defined(BLITZ_BUTTONS)
    M5.Lcd.println("Rally Computer");
    M5.Lcd.println("Blitz Buttons");
    M5.Lcd.setTextSize(1);
    M5.Lcd.println("Bluetooth Ready");
#elif defined(BLITZ_BUTTONS_WIRED)
    M5.Lcd.println("Rally Computer");
    M5.Lcd.println("Blitz Buttons");
    M5.Lcd.setTextSize(1);
    M5.Lcd.println("Wired Direct");
#endif
    
    M5.Lcd.println("Initializing...");
    delay(1000);
}

// Function to update the display with current GPS data
void updateDisplay() {
    // Get current GPS data
    float speed = getSpeed();
    float latitude = getLatitude();
    float longitude = getLongitude();
    bool gpsFixed = hasFix();
    
    // Clear screen
    M5.Lcd.fillScreen(BLACK);
    
    // Display title
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("Rally Computer");
    
    // Display GPS status
    M5.Lcd.setCursor(10, 40);
    if (gpsFixed) {
        M5.Lcd.setTextColor(GREEN);
        M5.Lcd.println("GPS: FIXED");
    } else {
        M5.Lcd.setTextColor(RED);
        M5.Lcd.println("GPS: SEARCHING...");
    }
    
    // Display speed (larger text)
    M5.Lcd.setTextSize(3);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setCursor(10, 70);
    M5.Lcd.print(speed, 1);
    M5.Lcd.println(" km/h");
    
    // Display coordinates
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(10, 110);
    M5.Lcd.print("Lat: ");
    M5.Lcd.println(latitude, 6);
    
    M5.Lcd.setCursor(10, 125);
    M5.Lcd.print("Lon: ");
    M5.Lcd.println(longitude, 6);
    
    // Display button interface based on device type
#ifdef M5STACK_CORE
    // Display physical button labels for M5Stack Core
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.setCursor(10, 220);
    M5.Lcd.print("A:Prev");
    M5.Lcd.setCursor(130, 220);
    M5.Lcd.print("B:Select");
    M5.Lcd.setCursor(240, 220);
    M5.Lcd.print("C:Next");
    
#elif defined(M5STACK_TOUGH)
    #ifdef USE_EXTERNAL_BUTTONS
        // Show external button status for M5Stack Tough
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(CYAN);
        M5.Lcd.setCursor(10, 150);
        M5.Lcd.println("External Buttons Active");
        
        // Also draw touch zones as backup
        M5.Lcd.drawRect(TOUCH_PREV_X, TOUCH_PREV_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT, DARKGREY);
        M5.Lcd.drawRect(TOUCH_SELECT_X, TOUCH_SELECT_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT, DARKGREY);
        M5.Lcd.drawRect(TOUCH_NEXT_X, TOUCH_NEXT_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT, DARKGREY);
        
        M5.Lcd.setTextColor(DARKGREY);
        M5.Lcd.setCursor(TOUCH_PREV_X + 25, TOUCH_PREV_Y + 25);
        M5.Lcd.print("PREV");
        M5.Lcd.setCursor(TOUCH_SELECT_X + 15, TOUCH_SELECT_Y + 25);
        M5.Lcd.print("SELECT");
        M5.Lcd.setCursor(TOUCH_NEXT_X + 25, TOUCH_NEXT_Y + 25);
        M5.Lcd.print("NEXT");
    #else
        // Draw active touch button zones for M5Stack Tough
        M5.Lcd.drawRect(TOUCH_PREV_X, TOUCH_PREV_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT, WHITE);
        M5.Lcd.drawRect(TOUCH_SELECT_X, TOUCH_SELECT_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT, WHITE);
        M5.Lcd.drawRect(TOUCH_NEXT_X, TOUCH_NEXT_Y, TOUCH_BUTTON_WIDTH, TOUCH_BUTTON_HEIGHT, WHITE);
        
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.setCursor(TOUCH_PREV_X + 25, TOUCH_PREV_Y + 25);
        M5.Lcd.print("PREV");
        M5.Lcd.setCursor(TOUCH_SELECT_X + 15, TOUCH_SELECT_Y + 25);
        M5.Lcd.print("SELECT");
        M5.Lcd.setCursor(TOUCH_NEXT_X + 25, TOUCH_NEXT_Y + 25);
        M5.Lcd.print("NEXT");
    #endif

#elif defined(BLITZ_BUTTONS)
    // Show Blitz Buttons connection status
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(10, 150);
    
    #ifdef BLITZ_BUTTONS
    extern BluetoothSerial SerialBT;  // Reference to the BluetoothSerial object
    if (SerialBT.hasClient()) {
        M5.Lcd.setTextColor(GREEN);
        M5.Lcd.println("Blitz Buttons Connected");
    } else {
        M5.Lcd.setTextColor(ORANGE);
        M5.Lcd.println("Waiting for Blitz Buttons...");
    }
    #endif
    
    // Show button mapping
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.setCursor(10, 190);
    M5.Lcd.print("Controls: Previous | Select | Next");
    M5.Lcd.setCursor(10, 205);
    M5.Lcd.print("Bluetooth: M5Stack_Rally_Computer");

#elif defined(BLITZ_BUTTONS_WIRED)
    // Show wired Blitz Buttons status
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.setCursor(10, 150);
    M5.Lcd.println("Blitz Buttons Connected (Wired)");
    
    // Show button mapping and GPIO pins
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.setCursor(10, 170);
    M5.Lcd.printf("GPIO: P=%d S=%d N=%d U=%d D=%d", 
                  BUTTON_PREVIOUS_PIN, BUTTON_SELECT_PIN, BUTTON_NEXT_PIN,
                  BUTTON_UP_PIN, BUTTON_DOWN_PIN);
    
    M5.Lcd.setCursor(10, 190);
    M5.Lcd.print("Controls: Prev | Select | Next | Up | Down");
    M5.Lcd.setCursor(10, 205);
    M5.Lcd.print("Direct wired - no Bluetooth needed");
#endif
}

// Function to draw a simple graphic (e.g., a rectangle)
void drawRectangle(int x, int y, int width, int height, uint16_t color) {
    M5.Lcd.fillRect(x, y, width, height, color);
}