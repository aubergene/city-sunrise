#include "./scenes/curtains.h"
#include "./scenes/sunRise.h"
#include "./scenes/temperature.h"
#include "./scenes/pressure.h"
#include "./scenes/humidity.h"
#include "./scenes/pollution.h"
#include "./scenes/redGreenYellow.h"

#define NUM_SCENES 5

int scene = 0;
int prevScene = -1;

void loop_scenes()
{
    // Advance the scene when the button is pushed
    if (buttonState == LOW)
    {
        // Check if it's the same as prevScreen so we can't advance
        // more than one scene from a single push
        if (prevScene == scene)
        {
            scene++;
            RotPosition = 0; // Reset the rotator for each scene

            // A transition between scenes, I thought it was overbarod
            // openCurtains(); // This is blocking and returns
        }
    }
    else
    {
        prevScene = scene;
    }

    // if (millis() > startedScene + sceneLen)
    // {
    //     startedScene = millis();
    //     scene++;
    //     if (scene >= NUM_SCENES)
    //     {
    //         scene = 0;
    //     }
    // }

    if (scene >= NUM_SCENES)
    {
        scene = 0;
        // Read from the sensor, the values don't change very rapidly
        // and the sensor is too slow (300ms+) to read in the normal loop
        loop_bme680();
    }

    display.print(scene + 1);
    display.print(F(": "));

    switch (scene)
    {
    case 0:
        display.println(F("Sun Rise"));
        sunRise();
        break;
    case 1:
        display.println(F("Temperature"));
        temperature();
        break;
    case 2:
        display.println(F("Pressure"));
        pressure();
        break;
    case 3:
        display.println(F("Humidity"));
        humidity();
        break;
    case 4:
        display.println(F("Pollution (VOC)"));
        pollution();
        break;
    }
}