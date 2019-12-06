#include "./scenes/curtains.h"
#include "./scenes/sunRise.h"
#include "./scenes/pollution.h"
#include "./scenes/temperature.h"
#include "./scenes/seaWaves.h"
#include "./scenes/redGreenYellow.h"

#define NUM_SCENES 4

int scene = 0;
int prevScene = -1;

void loop_scenes()
{
    if (buttonState == LOW)
    {
        if (prevScene == scene)
        {
            scene++;
            // TODO uncomment this when in prod
            // openCurtains(); // This is blocking and returns
            if (scene >= NUM_SCENES) {
                scene = 0;
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
        sunRise(knobValue);
        break;
    case 1:
        display.println(F("Sea Waves"));
        seaWaves();
        break;
    case 2:
        display.println(F("Thermometer"));
        temperature();
        break;
    case 3:
        display.println(F("redGreenYellow"));
        redGreenYellow();
        break;
    }

    // if (buttonState == HIGH && !buttonPushStart && buttonPushStart - millis() < 25) {
    //     buttonPushStart = millis();
    //     scene++;
    // }

    // if (buttonState == HIGH && !buttonPushStart && buttonPushStart - millis() < 25) {
}