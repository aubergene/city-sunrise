#include "./scenes/curtains.h"
#include "./scenes/sunRise.h"
#include "./scenes/temperature.h"
#include "./scenes/pressure.h"
#include "./scenes/pollution.h"
#include "./scenes/seaWaves.h"
#include "./scenes/redGreenYellow.h"

#define NUM_SCENES 5

int scene = 0;
int prevScene = -1;

void loop_scenes()
{
    if (buttonState == LOW)
    {
        if (prevScene == scene)
        {
            scene++;
            RotPosition = 0; // Reset the rotator for each scene

            // TODO uncomment this when in prod
            // openCurtains(); // This is blocking and returns
            if (scene >= NUM_SCENES) {
                scene = 0;
                loop_bme680(); // Read from the sensor
            }
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

    display.print(F("S"));
    display.print(scene);
    display.print(F(": "));

    switch (scene)
    {
    case 0:
        display.println(F("Sun Rise"));
        sunRise();
        break;
    case 1:
        display.println(F("Thermometer"));
        temperature();
        break;
    case 2:
        display.println(F("Pressure"));
        pressure();
        break;
    case 3:
        display.println(F("Sea Waves"));
        seaWaves();
        break;
    case 4:
        display.println(F("redGreenYellow"));
        redGreenYellow();
        break;
    }
}