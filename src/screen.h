/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/
#include "Arduino.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup_screen()
{
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }

    display.setTextSize(1);              // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text

    // Fancy intro display
    // first blank screen
    display.clearDisplay();
    display.setCursor(0, 0); // Start at top-left corner
    display.display();

    if (!skipIntro)
    {
        delay(200);

        // show name of project
        // display.println(F("CITY SUNRISE"));
        // display.display();

        display.setTextSize(2); // Draw 2X-scale text
        display.setTextColor(SSD1306_WHITE);
        display.println(F("CITY"));
        display.println(F("SUNRISE"));
        display.display();
        delay(2000);

        // then my name and Goldsmiths
        display.clearDisplay();
        display.setCursor(0, 0); // Start at top-left corner
        display.setTextSize(1);
        display.println(F("CITY SUNRISE"));
        display.println();
        display.println(F("Julian Burgess"));
        display.println(F("Goldsmiths 2019"));
        display.display();

        // ok clear it now and get on with the show!
        delay(3000);
        display.clearDisplay();
        display.display();
    }
}
