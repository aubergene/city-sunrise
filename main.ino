const int buttonPin = 2; // the number of the pushbutton pin
int buttonState = 0; // variable for reading the pushbutton status

const int knobPin = A0; // select the input pin for the potentiometer
int knobValue = 0;  // variable to store the value coming from the sensor

#include "src/bme680.h"
#include "src/screen.h"
#include "src/leds.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("resetting");

    pinMode(buttonPin, INPUT);

    setup_leds();
    setup_screen();
    // setup_bme680();
}

void loop()
{
    display.clearDisplay();
    display.setCursor(0, 0); // Start at top-left corner

    knobValue = analogRead(knobPin);

    int val = map(knobValue, 30, 1000, 0, 255);
    val = constrain(val, 0, 255);

    // Serial.println(knobValue);

    sunRise(val);
    // pollution(val);

    // loop_bme680();
    // loop_screen();
    // loop_scenes();
    // loop_leds();

    // delay(10);
}

