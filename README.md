# Open Rally Computer - ILI9341 Version

This version of the Open Rally Computer project uses a **2.8" 240x320 TFT LCD Display with ILI9341 Driver**. It is designed to work with the Adafruit Feather HUZZAH32 and other Feather-compatible hardware.

## Overview

The Open Rally Computer is a versatile project designed for rally navigation and data tracking. This version simplifies the hardware setup by using an ILI9341 TFT display, which provides a vibrant and high-resolution interface.

## Hardware Requirements

- **Microcontroller**: Adafruit Feather HUZZAH32 (ESP32-based)
- **Display**: 2.8" 240x320 TFT LCD with ILI9341 Driver
  - [Purchase Link](https://www.amazon.com/dp/B07T5CY8PP?_encoding=UTF8&tag=advrider-sl-20)
- **GPS Module**: Adafruit Ultimate GPS FeatherWing
- **External GPS Antenna**: Recommended for better reception due to stacked hardware
- **Buttons**: 3 tactile push buttons for navigation
- **Power Supply**: 3.7V LiPo battery or USB power
- **Logic Level Shifter**: Required if the display operates at 5V logic levels

## Wiring Instructions

### Display Wiring
| Display Pin | HUZZAH32 Pin | Description                     |
|-------------|--------------|---------------------------------|
| **VCC**     | USB (5V)     | Power supply (5V)              |
| **GND**     | GND          | Ground                         |
| **CS**      | GPIO 5       | Chip Select (via level shifter)|
| **DC**      | GPIO 16      | Data/Command (via level shifter)|
| **RST**     | GPIO 17      | Reset (via level shifter)      |
| **SCK**     | GPIO 18      | SPI Clock (via level shifter)  |
| **MOSI**    | GPIO 23      | SPI Data (via level shifter)   |

### Button Wiring
| Button       | HUZZAH32 Pin | Description                     |
|--------------|--------------|---------------------------------|
| **Previous** | GPIO 32      | Input for "Previous" button     |
| **Select**   | GPIO 33      | Input for "Select" button       |
| **Next**     | GPIO 34      | Input for "Next" button         |

### GPS FeatherWing
The GPS FeatherWing stacks directly on the HUZZAH32. Connect an external GPS antenna to the SMA connector for better reception.

## Software Requirements

### Libraries
Install the following libraries in the Arduino IDE:
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit ILI9341 Library](https://github.com/adafruit/Adafruit_ILI9341)
- [TinyGPS++ Library](https://github.com/mikalhart/TinyGPSPlus)

### Code Structure
The project follows the standard Arduino structure:
- **`setup()`**: Initializes the display, GPS, and buttons.
- **`loop()`**: Handles navigation, GPS data processing, and display updates.

## Features

- **ILI9341 Display**: High-resolution 240x320 TFT LCD with vibrant colors.
- **GPS Integration**: Tracks location and speed using the Adafruit Ultimate GPS FeatherWing.
- **User Input**: Three tactile buttons for navigation and interaction.
- **Modular Design**: Easy to expand with additional sensors or features.

## Getting Started

1. Assemble the hardware as per the wiring instructions.
2. Install the required libraries in the Arduino IDE.
3. Upload the code to the HUZZAH32 using the Arduino IDE or PlatformIO.
4. Power the device and enjoy your Open Rally Computer!

## Notes

- Ensure the display is powered with 5V if required.
- Use a logic level shifter if the display operates at 5V logic levels.
- Use an external GPS antenna for better reception.
- Test the hardware connections before uploading the code.

## License

This project is open-source and available for modification and redistribution under the MIT License.
