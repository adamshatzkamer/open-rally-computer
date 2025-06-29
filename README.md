# Open Rally Computer for M5Stack

!(https://raw.githubusercontent.com/adamshatzkamer/open-rally-computer/refs/heads/universal-m5stack-rally-computer/gray_cover_01.png)

A universal, open-source rally computer for motorcycles and adventure vehicles, supporting both M5Stack Core and M5Stack Tough hardware. This project supports multiple input methods: built-in buttons, touchscreen, external wired buttons, and Blitz Buttons (Bluetooth or wired).

---

## Table of Contents

- [Features](#features)
- [Supported Hardware](#supported-hardware)
- [Where to Buy M5Stack Hardware](#where-to-buy-m5stack-hardware)
- [Parts List / BOM](#parts-list--bom)
- [3D Print Models](#3d-print-models)
- [Switch Replacement Info](#switch-replacement-info)
- [Blitz Buttons Resources](#blitz-buttons-resources)
- [Flashing Instructions](#flashing-instructions)
- [Configuration](#configuration)
- [Wiring Guide](#wiring-guide)
- [Disclaimer on Switch Fit](#disclaimer-on-switch-fit)
- [License](#license)

---

## Features

- Real-time GPS speed, coordinates, and fix status
- Large, clear display for rally use
- Supports:
  - M5Stack Core (built-in buttons)
  - M5Stack Tough (touchscreen)
  - External wired buttons
  - Blitz Buttons (Bluetooth or wired)
- Visual feedback for button/touch input
- Designed for rugged, outdoor, and motorsport environments

---

## Supported Hardware

- **M5Stack Core**: [Product Page](https://shop.m5stack.com/products/core-basic-esp32-iot-development-kit)
- **M5Stack Tough**: [Product Page](https://shop.m5stack.com/products/m5stack-tough-esp32-iot-development-kit)
- **GPS Module**: Any NEO-6M/NEO-M8N or compatible UART GPS
- **External Buttons**: Waterproof momentary toggle switches (see below)
- **Blitz Buttons**: [ADVRider Blitz Buttons Thread](https://www.advrider.com/f/threads/blitz-buttons-bluetooth-digital-rally-remotes-rallyblitz-and-rally-navigator-compatible.1266762/)

---

## Where to Buy M5Stack Hardware

- [M5Stack Official Store](https://shop.m5stack.com/)
- [Amazon - M5Stack Core](https://www.amazon.com/s?k=m5stack+core)
- [Amazon - M5Stack Tough](https://www.amazon.com/s?k=m5stack+tough)
- [DigiKey - M5Stack](https://www.digikey.com/en/products/filter/rf-evaluation-and-development-kits/872?s=N4IgTCBcDaIMoFkCGBaA2ApgMwIYBsA9lANogC6AvkA)
- [Mouser - M5Stack](https://www.mouser.com/c/embedded-solutions/development-tools/development-boards-kits-accessories/?q=m5stack)

---

## Parts List / BOM

Based on [this Instructables project](https://www.instructables.com/Rally-Controller-With-Bluetooth/):

| Item                        | Example/Source                                                                 | Qty |
|-----------------------------|-------------------------------------------------------------------------------|-----|
| M5Stack Core or Tough       | [M5Stack Official](https://shop.m5stack.com/)                                 | 1   |
| GPS Module (NEO-6M/M8N)     | [Amazon Example](https://www.amazon.com/s?k=neo-6m+gps+module)                | 1   |
| Waterproof Toggle Switch    | See [Switch Replacement Info](#switch-replacement-info) below                  | 3   |
| Blitz Buttons (optional)    | [ADVRider Thread](https://www.advrider.com/f/threads/blitz-buttons-bluetooth-digital-rally-remotes-rallyblitz-and-rally-navigator-compatible.1266762/) | 1   |
| Enclosure (3D printed)      | See [3D Print Models](#3d-print-models)                                       | 1   |
| Wiring, connectors, etc.    | Local electronics supplier                                                    | as needed |

**For full BOM and wiring, see:**  
[Instructables Rally Controller With Bluetooth](https://www.instructables.com/Rally-Controller-With-Bluetooth/)

---

## 3D Print Models

- [Rally Blitz Buttons Enclosure on Thingiverse](https://www.thingiverse.com/thing:2754016)
- [Rally Computer Mounts and Accessories](https://www.thingiverse.com/search?q=rally+computer&type=things&sort=relevant)
- [Instructables 3D Print Files](https://www.instructables.com/Rally-Controller-With-Bluetooth/) (see "Files" section)

---

## Switch Replacement Info

**Original:** Honeywell 1MT1-7 (discontinued, expensive)

**Recommended Replacement:**  
- **E-Switch 100A12MS1V1QE**  
  - IP67 waterproof, SPDT (ON)-OFF-(ON), 12mm panel cutout, 19mm hex nut  
  - [Mouser Product Page](https://www.mouser.com/ProductDetail/E-Switch/100A12MS1V1QE?qs=Qbs%2F6Q%2F%252B8w%3D)  
  - [DigiKey Product Page](https://www.digikey.com/en/products/detail/e-switch/100A12MS1V1QE/612013)  
  - Price: ~$15–20 USD each (as of 2024)

**Alternative:**  
- **E-Switch 200A12MS1V1QE** (subminiature, same cutout)

**Other Brands:**  
- [C&K M2012SS1W01 at DigiKey](https://www.digikey.com/en/products/detail/c-k/M2012SS1W01/37779)
- [TE Connectivity ALCOSWITCH](https://www.digikey.com/en/products/filter/toggle-switches/111?s=N4IgTCBcDaIMoFkCGBaA2ApgMwIYBsA9lANogC6AvkA)

> **Note:**  
> If you are not using the original Honeywell 1MT1-7 switch, we **cannot guarantee fit** in your enclosure. Always verify dimensions before ordering or modifying your housing.

---

## Blitz Buttons Resources

- [Blitz Buttons ADVRider Thread](https://www.advrider.com/f/threads/blitz-buttons-bluetooth-digital-rally-remotes-rallyblitz-and-rally-navigator-compatible.1266762/)
- [Blitz Buttons Build Guide & BOM](https://www.instructables.com/Rally-Controller-With-Bluetooth/)
- [RallyBlitz App](https://apps.apple.com/us/app/rallyblitz/id593324622)
- [Rally Navigator](https://www.rallynavigator.com/)

---

## Flashing Instructions

### Prerequisites

- [VS Code](https://code.visualstudio.com/) with [PlatformIO extension](https://platformio.org/install/ide?install=vscode)
- USB-C (Tough) or micro-USB (Core) cable
- M5Stack device and drivers (see [M5Stack driver page](https://docs.m5stack.com/en/quick_start/m5core))

### Step-by-Step

1. **Clone this repository:**
   ```sh
   git clone https://github.com/adamshatzkamer/open-rally-computer.git
   cd open-rally-computer
   ```

2. **Open in VS Code**  
   Open the folder in VS Code.

3. **Connect your M5Stack**  
   Plug in via USB.  
   - On Mac, the port will look like `/dev/cu.usbserial-*`
   - On Windows, it will be `COMx`

4. **Select the correct PlatformIO environment**  
   - For M5Stack Core: `m5stack-core`
   - For M5Stack Tough: `m5stack-tough`
   - For Blitz Buttons: `m5stack-blitz-buttons`
   - For Wired Blitz Buttons: `m5stack-blitz-buttons-wired`

5. **Upload the firmware:**  
   In the VS Code terminal, run:
   ```sh
   pio run -e m5stack-core -t upload
   ```
   Replace `m5stack-core` with your hardware/environment.

6. **Monitor Serial Output (optional):**
   ```sh
   pio device monitor
   ```

### Troubleshooting

- If upload fails, check your USB cable and port.
- On Mac, you may need to install the [Silicon Labs CP210x driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers).
- If you see "Permission denied" errors, try:
  ```sh
  sudo chmod 777 /dev/cu.usbserial-*
  ```

---

## Configuration

Edit `src/config.h` to select your hardware and input method:

```cpp
// Choose ONE device type:
#define M5STACK_CORE      // Built-in buttons
// #define M5STACK_TOUGH     // Touchscreen

// For M5Stack Tough, optionally add:
// #define USE_EXTERNAL_BUTTONS  // Physical buttons + touchscreen

// For Blitz Buttons (Bluetooth or wired):
// #define BLITZ_BUTTONS_BLUETOOTH
// #define BLITZ_BUTTONS_WIRED
```

---

## Wiring Guide

**GPS Module:**
- GPS TX → GPIO 16 (M5Stack RX)
- GPS RX → GPIO 17 (M5Stack TX)
- GPS VCC → 3.3V
- GPS GND → GND

**External Buttons (if used):**
- Previous → GPIO 21 → GND
- Select   → GPIO 22 → GND
- Next     → GPIO 19 → GND

**Blitz Buttons (wired):**
- Wire outputs to GPIOs as above

---

## Disclaimer on Switch Fit

> **IMPORTANT:**  
> If you are not using the original Honeywell 1MT1-7 switch, we **cannot guarantee fit** in your enclosure. Always verify dimensions before ordering or modifying your housing. In fact, **we don't guarantee anything at all!** What do you expect, it's FOSS!

---

## License

This project is open-source under the MIT License.  
See [LICENSE](LICENSE) for details.

---
