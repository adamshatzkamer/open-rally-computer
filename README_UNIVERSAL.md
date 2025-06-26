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

## 🧰 Parts List / Bill of Materials (BOM)

**Based on the [Rally Controller With Bluetooth Instructable](https://www.instructables.com/Rally-Controller-With-Bluetooth/):**

- **3D printed shell** (see 3D Print Models below)
- **MCS18 Push Button IP65 round 18mm 48Vdc/125mA**, part no: 1241.1104.7097
- **Gasket for MCS18 to IP65**, part no: 0098.9201
- **Toggle switch (ON)-OFF-(ON) 1CO IP67/IP68**
  - *Original*: Honeywell 1MT1-7 (discontinued, expensive)
  - *Recommended Replacement*: C&K M2012SS1W01 or M2013SS1W01 (SPDT, waterproof, momentary, 12mm panel cutout)
    - Price: $12–$25 USD each
    - Order from: [DigiKey](https://www.digikey.com/), [Mouser](https://www.mouser.com/), [Newark](https://www.newark.com/)
    - Search: "C&K M-series waterproof toggle switch"
- **RND Signal cable 205-01148** – M8, 2m, 6 Pole, A-code, RND Connect, part no: RND 205-01148
- **M5 nuts and bolts**
- **O-ring** (outer diameter 13mm, rubber diameter 1.5mm)
- **Solder iron, cutters, small phillips screwdriver, super glue, small wrench**

**Bluetooth Unit (optional):**
- 3D printed case (see below)
- Bluetooth unit (premade or ESP32)
- Sensor cable, 6 Pole, M8, RND Connect part no: RND 205-01122
- Rubber O-ring 45mm OD, 3.3mm rubber
- M5 nuts, M5 screws 22mm
- 5mm drill

**ESP32 Version:**
- 3D printed case (see below)
- ESP32
- Sensor cable, 6 Pole, M8, RND Connect part no: RND 205-01122
- M4 15mm screws
- Micro USB cable

**ESP32 with Battery:**
- 3D printed case (see below)
- ESP32
- Sensor cable, 6 Pole, M8, RND Connect part no: RND 205-01122
- M4 15mm screws
- Single or double AA battery holder or 26650 Li-ion battery 3.6V (AA size)
- On-Off toggle, mounting hole 6x11mm

## 🖨️ 3D Print Models (Thingiverse)

- Handlebar Controller v1.0: [thing:4861162](https://www.thingiverse.com/thing:4861162)
- Handlebar Controller v2.0: [thing:4890343](https://www.thingiverse.com/thing:4890343)
- Buttons only: [thing:4890338](https://www.thingiverse.com/thing:4890338)
- Bluetooth Unit Case: [thing:4890354](https://www.thingiverse.com/thing:4890354)
- ESP32 with USB Case: [thing:4890356](https://www.thingiverse.com/thing:4890356)
- ESP32 with Battery Case: [thing:4861175](https://www.thingiverse.com/thing:4861175)

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

## 📝 Detailed Flashing Instructions (M5Stack Core & Tough)

### Prerequisites
- **Install [VS Code](https://code.visualstudio.com/) and [PlatformIO IDE](https://platformio.org/install/ide?install=vscode)**
- **Connect your M5Stack device to your computer via USB**
- For Windows: Install the [CP210x USB to UART Bridge VCP Drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) if your device is not detected

### Step-by-Step
1. **Clone or download this repository**
2. **Open the project folder in VS Code**
3. **Select the correct PlatformIO environment** (see below)
4. **Connect your M5Stack device via USB**
5. **Select the correct serial port** (if needed):
   - Click the PlatformIO icon (alien head) in the VS Code sidebar
   - Go to "Devices" to see available serial ports
   - If multiple ports are listed, unplug/replug your device to identify the correct one
6. **Build and upload the firmware:**
   - Open the VS Code terminal or use the PlatformIO toolbar
   - Run the following command for your device:
     - **M5Stack Core:**
       ```bash
       pio run -e m5stack-core -t upload
       ```
     - **M5Stack Tough:**
       ```bash
       pio run -e m5stack-tough -t upload
       ```
     - **M5Stack Tough + External Buttons:**
       ```bash
       pio run -e m5stack-tough-external -t upload
       ```
     - **Blitz Buttons (Bluetooth):**
       ```bash
       pio run -e m5stack-blitz-buttons -t upload
       ```
     - **Blitz Buttons (Wired):**
       ```bash
       pio run -e m5stack-blitz-buttons-wired -t upload
       ```
7. **Wait for the upload to complete.** The device will automatically reset and run the new firmware.

### Troubleshooting
- If upload fails, press and hold the reset button on the M5Stack while starting the upload, then release when you see "Connecting..."
- Make sure no other program (like Arduino IDE or serial monitor) is using the COM/serial port
- Try a different USB cable or port if the device is not detected
- For more help, see the [PlatformIO Docs](https://docs.platformio.org/en/latest/platforms/espressif32.html#m5stack-family)

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

## Blitz Buttons & Waterproof Switch Replacement

- The original Honeywell 1MT1-7 toggle switch is discontinued and expensive.
- **Recommended replacement:** C&K M2012SS1W01 or M2013SS1W01 (SPDT, waterproof, momentary, 12mm panel cutout)
  - Price: $12–$25 USD each
  - Order from: DigiKey, Mouser, Newark
  - Search: "C&K M-series waterproof toggle switch"
- These replacements are dimensionally compatible with the original and require little or no modification to the housing.
- **Note:** If you are not using the original Honeywell 1MT1-7 switch, we cannot guarantee the fit of any replacement switch in your housing. Always verify dimensions before ordering or modifying your enclosure.
