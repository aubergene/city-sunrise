const int MIN_PRESSURE = 950;
const int MAX_PRESSURE = 1050;
uint8_t gHue = 0; // rotating "base color"

void pressure()
{
    display.print(F("Pressure: "));
    display.print(bme.pressure / 100.0);
    display.println(F("mBar"));

    int sensorPressure;

    EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow

    const int MIN_ROT = -30;
    const int MAX_ROT = 30;

    rotPos = constrain(rotPos, MIN_ROT, MAX_ROT);

    // FastLED.clear();
    if (fakeSensor)
    {
        sensorPressure = mapC(rotPos, MIN_ROT, MAX_ROT, MIN_PRESSURE, MAX_PRESSURE);
        display.print(F("Fake pressure: "));
        display.println(sensorPressure);
    }
    else
    {
        sensorPressure = bme.pressure / 100.0;
    }

    // Low pressure == fast speed
    int speed = mapC(sensorPressure, MIN_PRESSURE, MAX_PRESSURE, 30, 5);

    // a colored dot sweeping back and forth, with fading trails
    fadeToBlackBy(leds, NUM_LEDS, 20);
    int pos = beatsin16(speed, 0, 120);
    leds[pos] += CHSV(gHue, 255, 192);

    pos = beatsin16(speed, 80, 220);
    leds[pos] += CHSV(gHue+60, 255, 192);

    pos = beatsin16(speed, 180, 299);
    leds[pos] += CHSV(gHue+120, 255, 192);

    FastLED.show();
}
