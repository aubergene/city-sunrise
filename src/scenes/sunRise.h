const int SUNRISE = 60 * 1000;  // length of sunrise in ms
const int SUNRISE_STEPS = 1000; // how many steps to take

void sunRise()
{
    const int mid = NUM_LEDS / 2;

    if (rotPos < 0)
    {
        rotPos = 0;
    }

    int sceneMillis = millis() - sceneStartMillis;
    int sunrise = mapC(sceneMillis, 0, SUNRISE, 0, SUNRISE_STEPS);

    FastLED.clear();

    display.print(F("sunrise: "));
    display.println(sunrise);

    int minV = mapC(sunrise, 0, SUNRISE_STEPS * 0.6, 40, 110);
    int maxV = mapC(sunrise, 100, SUNRISE_STEPS, 50, 210);

    int hueV = mapC(sunrise, 0, SUNRISE_STEPS * 0.8, 0, 60);

    // display.print(F("minV: "));
    // display.print(minV);
    // display.print(F(" maxV: "));
    // display.print(maxV);
    // display.print(F(" hueV: "));
    // display.println(hueV);

    int h, v;

    for (int i = 0; i < mid; i++)
    {
        h = map(i, 0, mid, hueV, 0);
        v = mapC(i, 0, mid, maxV, minV);
        leds[mid - i] = CHSV(h, 200, gamma8[v]);
        leds[mid + i] = CHSV(h, 200, gamma8[v]);
    }

    FastLED.show();
}
