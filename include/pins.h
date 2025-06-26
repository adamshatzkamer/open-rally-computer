// Open Rally Computer
// Copyright (C) 2021  Matías Godoy

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.


#pragma once

// Pin definitions for the ILI9341 display
#define TFT_CS   5    // Chip Select
#define TFT_DC   16   // Data/Command
#define TFT_RST  17   // Reset
#define TFT_SCK  18   // SPI Clock
#define TFT_MOSI 23   // SPI Data (MOSI)

#define PIN_TOUCH_CS        33
#define PIN_TOUCH_IRQ       32

// Remove or comment out old display pins
// #define PIN_DISPLAY_CLOCK     13
// #define PIN_DISPLAY_DATA      12
// #define PIN_DISPLAY_CS        14
// #define PIN_DISPLAY_DC        25
// #define PIN_DISPLAY_RESET     27

#define PIN_BUTTON_PREV       32
#define PIN_BUTTON_SELECT     33
#define PIN_BUTTON_NEXT       34
#define PIN_BACKLIGHT         26
#define PIN_GPS_RX            16
#define PIN_GPS_TX            17
#define PIN_THERMISTOR        15
