#define NUM_SCENES 4

int scene = 0;
int startedScene = 0;
const int sceneLen = 5000;

void loop_scenes()
{

    if (millis() > startedScene + sceneLen)
    {
        startedScene = millis();
        scene++;
        if (scene >= NUM_SCENES)
        {
            scene = 0;
        }
    }

    switch (scene)
    {
    case 0:
        display.println(F("openCurtains"));
        openCurtains();
        break;
    case 1:
        display.println(F("seaWaves"));
        seaWaves();
        break;
    case 2:
        display.println(F("bounceDot"));
        // bounceDot();
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