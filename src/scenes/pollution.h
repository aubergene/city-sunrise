const int MIN_GAS_RESIST = 4000;
const int MAX_GAS_RESIST = 6000;

void pollution()
{
    if (bme.gas_resistance == 0)
    {
        // gas readings are slower, so keep reading until we get one...
        loop_bme680();
        return;
    }

    display.print(F("Gas resist: "));
    display.println(bme.gas_resistance);

    float sensorResistance;

    const int MIN_ROT = -20;
    const int MAX_ROT = 20;

    rotPos = constrain(rotPos, MIN_ROT, MAX_ROT);

    if (fakeSensor)
    {
        sensorResistance = mapC(rotPos, MIN_ROT, MAX_ROT, MIN_GAS_RESIST, MAX_GAS_RESIST);
        display.print(F("Fake gas: "));
        display.println(sensorResistance);
    }
    else
    {
        sensorResistance = bme.gas_resistance / 1000.0;
    }

    // Low pressure == fast speed
    int pollutionLevel = mapC(sensorResistance, MIN_GAS_RESIST, MAX_GAS_RESIST, 1, 50);

    fadeToBlackBy(leds, NUM_LEDS, 20);

    for (int i = 0; i < NUM_LEDS; i++)
    {
        if (random16(10000) < pollutionLevel)
        {
            leds[random16(NUM_LEDS)] += CRGB::Purple;
        }
    }

    FastLED.show();
}
