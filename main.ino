#include "src/helpers.h"
#include "src/button.h"
#include "src/knob.h"
#include "src/bme680.h"
#include "src/screen.h"
#include "src/leds.h"
#include "src/scenes.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("resetting");

    setup_button();
    setup_knob();
    setup_leds();
    setup_screen();
    setup_bme680();
}

void loop()
{
    display.clearDisplay();
    display.setCursor(0, 0); // Start at top-left corner

    loop_button();
    loop_knob(); // get the reading from variable resistor
    loop_bme680(); // get the reading from the sensor
    loop_scenes(); // get the reading from variable resistor

    // display.println(millis());
    // display.println(knobValue);

    // display.println(knobValue);
    // display.println(buttonState);
    // display.println(scene);

    // display.println(buttonState);
    // display.print(F("Temp: "));
    // display.println(bme.temperature);
    display.display();

    // pollution(val);
}
