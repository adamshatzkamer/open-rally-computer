# Open Rally Computer - M5Stack Tough Version

This version of the Open Rally Computer project is designed to work with the **M5Stack Tough ESP32 IoT Development Board**. It utilizes a **2.8" 240x320 TFT LCD Display with ILI9341 Driver** for a vibrant and high-resolution interface, making it suitable for rally navigation and data tracking.

## Overview

The Open Rally Computer is a versatile project aimed at providing essential navigation and data tracking features for rally enthusiasts. This version is optimized for the M5Stack Tough board, ensuring compatibility and ease of use.

## Hardware Requirements

- **Microcontroller**: M5Stack Tough ESP32
- **Display**: 2.8" 240x320 TFT LCD with ILI9341 Driver
- **GPS Module**: Adafruit Ultimate GPS FeatherWing
- **External GPS Antenna**: Recommended for better reception
- **Buttons**: 3 tactile push buttons for navigation
- **Power Supply**: 3.7V LiPo battery or USB power

## Wiring Instructions

### Display Wiring
| Display Pin | M5Stack Pin | Description                     |
|-------------|-------------|---------------------------------|
| **VCC**     | 5V          | Power supply (5V)              |
| **GND**     | GND         | Ground                          |
| **CS**      | GPIO 5      | Chip Select                     |
| **DC**      | GPIO 16     | Data/Command                    |
| **RST**     | GPIO 17     | Reset                           |
| **SCK**     | GPIO 18     | SPI Clock                       |
| **MOSI**    | GPIO 23     | SPI Data                        |

### Button Wiring
| Button       | M5Stack Pin | Description                     |
|--------------|-------------|---------------------------------|
| **Previous** | GPIO 32     | Input for "Previous" button     |
| **Select**   | GPIO 33     | Input for "Select" button       |
| **Next**     | GPIO 34     | Input for "Next" button         |

### GPS Module
The GPS module can be connected directly to the M5Stack Tough board. Ensure proper connections for reliable GPS data reception.

## Software Requirements

### Libraries
Install the following libraries in the Arduino IDE or PlatformIO:
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
2. Install the required libraries in the Arduino IDE or PlatformIO.
3. Upload the code to the M5Stack Tough using the Arduino IDE or PlatformIO.
4. Power the device and enjoy your Open Rally Computer!

## Notes

- Ensure the display is powered with 5V if required.
- Use an external GPS antenna for better reception.
- Test the hardware connections before uploading the code.

## License

This project is open-source and available for modification and redistribution under the MIT License.