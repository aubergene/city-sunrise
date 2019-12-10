const bool fakeSensor = false;
const bool skipIntro = false;

#include "src/helpers.h"
#include "src/button.h"
#include "src/rotator.h"
#include "src/bme680.h"
#include "src/screen.h"
#include "src/leds.h"
#include "src/scenes.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("resetting");

    setup_button();
    setup_rotator();
    setup_leds();
    setup_screen();
    setup_bme680();

    loop_bme680(); // Get first reading
    sceneStartMillis = millis();
}

void loop()
{
    display.clearDisplay();
    display.setCursor(0, 0); // Start at top-left corner

    loop_button();  // check if button has been pressed
    loop_rotator(); // get the reading from rotator
    loop_scenes();

    // display.println(millis());
    if (fakeSensor)
    {
        display.print("rotPos: ");
        display.println(rotPos);
    }

    display.display();
}
