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
#include <Adafruit_HX8357.h>
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

// Initialize the TFT FeatherWing display
Adafruit_HX8357 tft = Adafruit_HX8357(PIN_TFT_CS, PIN_TFT_DC, PIN_TFT_RESET);

// Initialize display
void initializeDisplay() {
  tft.begin();
  tft.setRotation(1); // Landscape mode
  tft.fillScreen(HX8357_BLACK);
  tft.setTextColor(HX8357_WHITE);
  tft.setTextSize(2);

  // Turn on the backlight
  pinMode(PIN_TFT_BACKLIGHT, OUTPUT);
  digitalWrite(PIN_TFT_BACKLIGHT, HIGH);
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
