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


#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <display.h>
#include <screens/splash.h>
#include <screens/odometer.h>
#include <screens/speed.h>
#include <screens/time.h>
#include <screens/heading.h>
#include <screens/settings.h>
#include <screens/input.h>
#include <screens/language.h>
#include <screens/gps.h>
#include <screens/update.h>
#include <pins.h>
#include <memory.h>

// Define the ILI9341 display object
Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);

// Function to initialize the display
void setupDisplay() {
  tft.begin(); // Initialize the display
  tft.setRotation(1); // Set display orientation to landscape
  tft.fillScreen(ILI9341_BLACK); // Clear the screen with black
  tft.setTextColor(ILI9341_WHITE); // Set text color to white
  tft.setTextSize(2); // Set text size
  tft.setCursor(10, 10); // Set cursor position
  tft.println("Open Rally Computer"); // Display a welcome message
}

void drawSplashScreen() {
  tft.fillScreen(HX8357_BLUE);
  tft.setCursor(50, 120);
  tft.print("Open Rally Computer");
}

void drawScreen(int index) {
  switch (index) {
    case SCREEN_SPLASH:
      drawSplashLayout();
      break;
    case SCREEN_ODOMETER:
      drawOdometerLayout();
      break;
    case SCREEN_SPEED:
      drawSpeedLayout();
      break;
    case SCREEN_TIME:
      drawTimeLayout();
      break;
    case SCREEN_HEADING:
      drawHeadingLayout();
      break;
    case SCREEN_MENU:
      drawSettingsLayout();
      break;
    case SCREEN_INPUT:
      drawInputLayout();
      break;
    case SCREEN_LANGUAGE:
      drawLanguageLayout();
      break;
    case SCREEN_GPS:
      drawGpsLayout();
      break;
    case SCREEN_UPDATE:
      drawUpdateLayout();
      break;
    default:
      drawOdometerLayout();
      break;
  }
}
