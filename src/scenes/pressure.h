const int MIN_PRESSURE = 950;
const int MAX_PRESSURE = 1050;

void pressure()
{
    display.print(F("Pressure: "));
    display.print(bme.pressure / 100.0);
    display.println(F(" mBars"));

    int sensorPressure;

    const int MIN_ROT = -30;
    const int MAX_ROT = 30;

    RotPosition = constrain(RotPosition, MIN_ROT, MAX_ROT);

    // FastLED.clear();
    if (fakeSensor)
    {
        sensorPressure = mapC(RotPosition, MIN_ROT, MAX_ROT, MIN_PRESSURE, MAX_PRESSURE);
        display.print(F("Fake pressure: "));
        display.println(sensorPressure);
    }
    else
    {
        sensorPressure = bme.pressure / 100.0;
    }

    int speed = mapC(sensorPressure, MIN_PRESSURE, MAX_PRESSURE, 20, 40);

    // a colored dot sweeping back and forth, with fading trails
    fadeToBlackBy(leds, NUM_LEDS, 20);
    int pos = beatsin16(speed, 0, 120);
    leds[pos] += CHSV(0, 255, 192);

    pos = beatsin16(speed, 80, 220);
    leds[pos] += CHSV(60, 255, 192);

    pos = beatsin16(speed, 180, 299);
    leds[pos] += CHSV(120, 255, 192);

    FastLED.show();
}
