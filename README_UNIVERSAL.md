# Open Rally Computer - M5Stack Universal Version

A rally computer application that runs on both M5Stack Core and M5Stack Tough devices, providing GPS tracking, speed monitoring, and navigation controls.

## 🎯 Supported Devices

### M5Stack Core
- **Input**: 3 built-in physical buttons (A, B, C)
- **Display**: 320x240 LCD
- **Connector**: Micro-USB
- **Best for**: Budget builds, desk testing

### M5Stack Tough  
- **Input**: Touchscreen + optional external buttons
- **Display**: 320x240 LCD with touch
- **Connector**: USB-C
- **Features**: Rugged/waterproof design
- **Best for**: Rally/automotive use

### M5Stack with Blitz Buttons (Bluetooth) 🎉
- **Input**: Professional Bluetooth rally remotes
- **Display**: 320x240 LCD (Core or Tough)
- **Features**: Wireless, handlebar-mounted, weatherproof
- **Best for**: Clean wireless rally setups
- **Build Guide**: [Blitz Buttons Instructions on ADVRider](https://www.advrider.com/f/threads/blitz-buttons-bluetooth-digital-rally-remotes-rallyblitz-and-rally-navigator-compatible.1266762/page-9#post-44377507)

### M5Stack with Blitz Buttons (Wired) ⚡
- **Input**: Professional rally buttons (direct wired)
- **Display**: 320x240 LCD (Core or Tough)  
- **Features**: Zero latency, no pairing, always connected
- **Best for**: Maximum reliability rally setups
- **Build Guide**: [Blitz Buttons Instructions on ADVRider](https://www.advrider.com/f/threads/blitz-buttons-bluetooth-digital-rally-remotes-rallyblitz-and-rally-navigator-compatible.1266762/page-9#post-44377507) (skip Bluetooth module for wired version)

## 🔧 Configuration

### Device Selection
Edit `src/config.h` and uncomment ONE option:

```cpp
#define M5STACK_CORE         // For M5Stack Core
// #define M5STACK_TOUGH        // For M5Stack Tough
// #define BLITZ_BUTTONS        // For Blitz Buttons (Bluetooth)
// #define BLITZ_BUTTONS_WIRED  // For Blitz Buttons (Direct Wired)
```

### External Buttons (M5Stack Tough only)
To add external buttons to M5Stack Tough, also uncomment:

```cpp
#define USE_EXTERNAL_BUTTONS
```

### Blitz Buttons Configuration
When using `BLITZ_BUTTONS`, customize the command mapping in `config.h`:

```cpp
// Keyboard commands sent by your Blitz Buttons
#define BLITZ_CMD_PREVIOUS  'p'    // Previous button
#define BLITZ_CMD_SELECT    's'    // Select button  
#define BLITZ_CMD_NEXT      'n'    // Next button

// Or use function keys if that's what your setup sends
// #define BLITZ_USE_FUNCTION_KEYS
```

## 🔌 Hardware Connections

### GPS Module (All versions)
```
GPS Module → M5Stack
VCC        → 3.3V
GND        → GND
TX         → GPIO 16 (RX)
RX         → GPIO 17 (TX)
```

### External Buttons (M5Stack Tough only)
```
Button 1 (Previous) → GPIO 21 → GND
Button 2 (Select)   → GPIO 22 → GND  
Button 3 (Next)     → GPIO 19 → GND
```

### Blitz Buttons (Bluetooth - No wiring needed! 🎉)
1. **Power on** your existing Blitz Buttons system
2. **Enable pairing mode** on Blitz Buttons (refer to your build instructions)
3. **Power on** M5Stack with Blitz Buttons firmware
4. **Connect** Blitz Buttons to "M5Stack_Rally_Computer"
5. **You're ready to rally!**

### Blitz Buttons (Direct Wired - Maximum reliability! ⚡)
Instead of using the Bluetooth module in your Blitz Buttons, wire the button outputs directly:

```
Blitz Button 1 (Previous) → GPIO 21
Blitz Button 2 (Select)   → GPIO 22  
Blitz Button 3 (Next)     → GPIO 19
Blitz Button 4 (Up)       → GPIO 25 (optional)
Blitz Button 5 (Down)     → GPIO 26 (optional)
All button commons        → GND
```

**Wiring Notes:**
- **Skip the Bluetooth module** in your Blitz Buttons build
- **Wire button outputs** directly to M5Stack GPIO pins
- **Use the same membrane switches** and button housing
- **M5Stack provides pull-up resistors** internally
- **Configure `BLITZ_ACTIVE_LOW`** in config.h based on your button logic
- **Full build instructions**: [ADVRider Blitz Buttons Thread](https://www.advrider.com/f/threads/blitz-buttons-bluetooth-digital-rally-remotes-rallyblitz-and-rally-navigator-compatible.1266762/page-9#post-44377507)

*Note: External buttons use internal pull-up resistors*

## 🚀 Building and Uploading

### Method 1: PlatformIO Environments

Choose the appropriate environment:

```bash
# M5Stack Core with built-in buttons
pio run -e m5stack-core
pio run -e m5stack-core -t upload

# M5Stack Tough with touchscreen only
pio run -e m5stack-tough  
pio run -e m5stack-tough -t upload

# M5Stack Tough with external buttons + touchscreen
pio run -e m5stack-tough-external
pio run -e m5stack-tough-external -t upload

# M5Stack with Blitz Buttons (Bluetooth HID)
pio run -e m5stack-blitz-buttons
pio run -e m5stack-blitz-buttons -t upload

# M5Stack with Blitz Buttons (Direct Wired)
pio run -e m5stack-blitz-buttons-wired
pio run -e m5stack-blitz-buttons-wired -t upload
```

### Method 2: Manual Configuration

1. Edit `src/config.h` to select your device
2. Build with default environment:
```bash
pio run
pio run -t upload
```

## 🎮 Controls

### M5Stack Core
- **Button A**: Previous/Back
- **Button B**: Select/Enter  
- **Button C**: Next/Forward

### M5Stack Tough (Touchscreen)
- **Touch zones** at bottom of screen
- **Left zone**: Previous/Back
- **Center zone**: Select/Enter
- **Right zone**: Next/Forward

### M5Stack Tough (External Buttons)
- **Physical buttons** take priority over touchscreen  
- **Touchscreen** works as backup
- Same button mapping as M5Stack Core

### Blitz Buttons (Bluetooth HID)
- **Wireless operation** - no cables to handlebars
- **Professional tactile buttons** - perfect for gloves
- **Weatherproof design** - rally-tested reliability
- **Custom key mapping** - configurable in firmware
- **Connection status** displayed on M5Stack screen

### Blitz Buttons (Direct Wired)
- **Zero latency** - instant button response
- **Always connected** - no pairing issues
- **Lower power** - no Bluetooth radio needed
- **Maximum reliability** - no wireless interference
- **Professional buttons** - same quality tactile feel
- **Up to 5 buttons** - Previous, Select, Next, Up, Down

## 📊 Display Features

- **GPS Status**: Shows FIXED/SEARCHING
- **Speed**: Large display in km/h
- **Coordinates**: Latitude/Longitude with 6 decimal precision
- **Button indicators**: Visual feedback for controls
- **Device identification**: Shows which M5Stack version is running

## 🏁 Rally Computer Features

- **Real-time GPS tracking**
- **Speed monitoring** 
- **Coordinate display**
- **Weather-resistant** (M5Stack Tough)
- **Glove-friendly interface** (touchscreen)
- **Vibration resistant** (external buttons option)
- **Serial debugging** for troubleshooting

## 🔗 Blitz Buttons Resources

### Build Your Own Blitz Buttons
- **Complete Instructions**: [ADVRider Blitz Buttons Thread](https://www.advrider.com/f/threads/blitz-buttons-bluetooth-digital-rally-remotes-rallyblitz-and-rally-navigator-compatible.1266762/page-9#post-44377507)
- **Parts List & BOM**: Detailed in the ADVRider thread
- **3D Print Files**: Links provided in the thread
- **Wiring Diagrams**: Step-by-step assembly guide
- **Software**: RallyBlitz firmware for Bluetooth version

### Integration Options
- **Bluetooth Version**: Use complete Blitz Buttons system wirelessly
- **Wired Version**: Skip Bluetooth module, wire buttons directly to M5Stack
- **Both supported**: Same professional button quality and housing

*The ADVRider community has done excellent work documenting this build!*

## 🔧 Troubleshooting

### GPS Not Working
- Check wiring connections
- Verify GPS module power (3.3V)
- Move to open sky area for GPS fix
- Check serial monitor for GPS data

### Buttons Not Responding
- **M5Stack Core**: Built-in buttons should work automatically
- **M5Stack Tough**: Check touchscreen calibration
- **External buttons**: Verify GPIO connections and pull-up resistors

### Serial Monitor Output
```
=================================
Rally Computer Starting...
Device: M5Stack Tough
Input: External buttons + Touchscreen
=================================
GPS initialized
External buttons initialized on M5Stack Tough
Rally Computer Ready!
```

## 📱 Perfect for Rally Use

The M5Stack Tough version with external buttons provides the ideal rally computer setup:

- **Rugged touchscreen** for normal operation
- **Physical buttons** for use with gloves/in rough conditions  
- **Dual input methods** ensure reliability
- **Weather-resistant** design
- **Automotive-grade** durability

Choose the configuration that best fits your rally setup!
