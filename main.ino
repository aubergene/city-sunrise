const int buttonPin = 2; // the number of the pushbutton pin
int buttonState = 0;     // variable for reading the pushbutton status

const int numReadings = 10;
const int knobPin = A0; // select the input pin for the potentiometer
int knobValue;          // variable to store the value coming from the sensor
int knobValues[numReadings];
int knobIndex = 0; // variable to store our position in the array

#include "src/bme680.h"
#include "src/screen.h"
#include "src/leds.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("resetting");

    for (int i = 0; i < numReadings; i++)
    {
        knobValues[i] = 0;
    }

    pinMode(buttonPin, INPUT);

    setup_leds();
    setup_screen();
    setup_bme680();
}

void loop()
{
    display.clearDisplay();
    display.setCursor(0, 0); // Start at top-left corner

    // knobValue = analogRead(knobPin);
    knobValues[knobIndex++] = analogRead(knobPin);
    if (knobIndex == numReadings)
    {
        knobIndex = 0;
    }
    int knobSum = 0;
    for (int i = 0; i < numReadings; i++)
    {
        knobSum += knobValues[i];
        Serial.print(knobValues[i]);
        Serial.print("\t");
    }
    knobValue = knobSum / numReadings;

    int val = map(knobValue, 50, 1000, 0, 255);
    val = constrain(val, 0, 255);

    Serial.println();

    // loop_bme680(); // get the reading from the sensor

    sunRise(val);
    // sensorTemp();

    // delay(60 * 1000);
    // pollution(val);

    // loop_bme680();
    // loop_screen();
    // loop_scenes();
    // loop_leds();

    delay(10);
}
