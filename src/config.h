// config.h - Configuration for both M5Stack Core and M5Stack Tough

#ifndef CONFIG_H
#define CONFIG_H

// ========================================
// DEVICE SELECTION - Uncomment ONE option
// ========================================
#define M5STACK_CORE      // Use M5Stack Core with built-in buttons
// #define M5STACK_TOUGH     // Use M5Stack Tough with touchscreen
// #define BLITZ_BUTTONS     // Use M5Stack with Blitz Buttons (Bluetooth)
// #define BLITZ_BUTTONS_WIRED // Use M5Stack with Blitz Buttons (Direct Wired)

// Optional: Add external buttons to M5Stack Tough
#ifdef M5STACK_TOUGH
// #define USE_EXTERNAL_BUTTONS  // Uncomment to enable external buttons on Tough
#endif

// ========================================
// DISPLAY SETTINGS
// ========================================
#define TFT_CS    14
#define TFT_DC    27
#define TFT_RST   33
#define TFT_MOSI  23
#define TFT_CLK   18
#define TFT_MISO  19

const int displayWidth = 320;   // Display width
const int displayHeight = 240;  // Display height

// ========================================
// GPS MODULE SETTINGS
// ========================================
#define GPS_RX_PIN 16  // Connect GPS TX to this pin
#define GPS_TX_PIN 17  // Connect GPS RX to this pin

// ========================================
// BUTTON CONFIGURATION
// ========================================

// ========================================
// BUTTON CONFIGURATION
// ========================================

#ifdef M5STACK_CORE
    // M5Stack Core built-in button pins
    #define BUTTON_A_PIN     39  // Left button
    #define BUTTON_B_PIN     38  // Middle button 
    #define BUTTON_C_PIN     37  // Right button
    
    // Button aliases
    #define BUTTON_PREVIOUS_PIN BUTTON_A_PIN
    #define BUTTON_SELECT_PIN   BUTTON_B_PIN
    #define BUTTON_NEXT_PIN     BUTTON_C_PIN
    
#elif defined(M5STACK_TOUGH)
    // M5Stack Tough touchscreen settings
    #define TOUCH_BUTTON_HEIGHT 60
    #define TOUCH_BUTTON_WIDTH  100
    
    // Touch zones (bottom of screen)
    #define TOUCH_PREV_X    10
    #define TOUCH_PREV_Y    180
    #define TOUCH_SELECT_X  110  
    #define TOUCH_SELECT_Y  180
    #define TOUCH_NEXT_X    210
    #define TOUCH_NEXT_Y    180
    
    #ifdef USE_EXTERNAL_BUTTONS
        // External button pins for M5Stack Tough
        #define EXT_BUTTON_1_PIN  21  // External button 1 (Previous)
        #define EXT_BUTTON_2_PIN  22  // External button 2 (Select)
        #define EXT_BUTTON_3_PIN  19  // External button 3 (Next)
        
        // Button aliases
        #define BUTTON_PREVIOUS_PIN EXT_BUTTON_1_PIN
        #define BUTTON_SELECT_PIN   EXT_BUTTON_2_PIN
        #define BUTTON_NEXT_PIN     EXT_BUTTON_3_PIN
    #endif

#elif defined(BLITZ_BUTTONS)
    // Blitz Buttons Bluetooth HID configuration
    #define BLITZ_DEVICE_NAME "BlitzButtons"  // Bluetooth device name to connect to
    
    // Keyboard commands sent by Blitz Buttons (customize these based on your setup)
    #define BLITZ_CMD_PREVIOUS  'p'    // Previous button command
    #define BLITZ_CMD_SELECT    's'    // Select/Enter button command  
    #define BLITZ_CMD_NEXT      'n'    // Next button command
    #define BLITZ_CMD_UP        'u'    // Up button command (if using 4-button setup)
    #define BLITZ_CMD_DOWN      'd'    // Down button command (if using 4-button setup)
    
    // Alternative: Use function keys (F1, F2, F3, etc.) if that's what your Blitz Buttons send
    // #define BLITZ_USE_FUNCTION_KEYS
    #ifdef BLITZ_USE_FUNCTION_KEYS
        #define BLITZ_CMD_PREVIOUS  0x3A  // F1 key code
        #define BLITZ_CMD_SELECT    0x3B  // F2 key code
        #define BLITZ_CMD_NEXT      0x3C  // F3 key code
    #endif

#elif defined(BLITZ_BUTTONS_WIRED)
    // Blitz Buttons Direct Wired configuration
    // Connect button outputs directly to M5Stack GPIO pins
    
    // GPIO pins for wired Blitz Buttons (avoid GPS pins 16,17)
    #define BLITZ_BUTTON_1_PIN  21  // Previous button
    #define BLITZ_BUTTON_2_PIN  22  // Select button  
    #define BLITZ_BUTTON_3_PIN  19  // Next button
    #define BLITZ_BUTTON_4_PIN  25  // Up button (optional 4th button)
    #define BLITZ_BUTTON_5_PIN  26  // Down button (optional 5th button)
    
    // Button aliases for easy reference
    #define BUTTON_PREVIOUS_PIN BLITZ_BUTTON_1_PIN
    #define BUTTON_SELECT_PIN   BLITZ_BUTTON_2_PIN
    #define BUTTON_NEXT_PIN     BLITZ_BUTTON_3_PIN
    #define BUTTON_UP_PIN       BLITZ_BUTTON_4_PIN
    #define BUTTON_DOWN_PIN     BLITZ_BUTTON_5_PIN
    
    // Button press logic (depends on your Blitz Buttons output)
    // If your buttons pull LOW when pressed, use true
    // If your buttons pull HIGH when pressed, use false
    #define BLITZ_ACTIVE_LOW    true
#endif

#endif // CONFIG_H