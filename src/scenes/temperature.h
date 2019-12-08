// temp refers to temperature not temporary as usually the case in code
const int tempFlashInterval = 500; // Flash interval in milliseconds
const int tempWidth = 6;           // Width of flashing area in pixels
int tempLastFlash = 0;             // Store last time flash was on
int tempFlash = false;             // Initial value of flash

// Guessed suitable domain for outdoors values from here
// https://en.wikipedia.org/wiki/Climate_of_London
// const int MIN_TEMP = 2;
// const int MAX_TEMP = 24;

// Better values for indoors
const int MIN_TEMP = 4;
const int MAX_TEMP = 32;

void temperature()
{
    display.print(F("Sensor temp: "));
    display.print(bme.temperature);
    display.print((char)247); // ° degree symbol
    display.println(F("C"));

    FastLED.clear();

    int sat = 255;
    int val = 180;

    int margin = 30;
    int p1 = 100;
    int p2 = NUM_LEDS - 1;

    // Use the fill for a blue gradient
    fill_gradient(leds, 0, CHSV(160, sat, val), p1, CHSV(160, sat, 0), SHORTEST_HUES);
    // Use the fill for a red gradient
    fill_gradient(leds, p1, CHSV(0, sat, 0), p2, CHSV(0, sat, val), SHORTEST_HUES);

    // Add yellow the patch in between the gradients
    for (int i = 0; i < 160; i++)
    {
        val = sin8(i * 1);
        int x = p1 - margin + i;
        leds[x] += CHSV(72, sat, gamma8[val]);
    }

    // Use a timer to turn on/off
    if (millis() - tempLastFlash > tempFlashInterval)
    {
        tempLastFlash = millis();
        tempFlash = !tempFlash;
    }

    float sensorTemp;

    if (fakeSensor)
    {
        const int MIN_ROT = -10;
        const int MAX_ROT = 40;

        rotPos = constrain(rotPos, MIN_ROT, MAX_ROT);

        // Uncomment to use knob value instead
        sensorTemp = mapC(rotPos, MIN_ROT, MAX_ROT, MIN_TEMP, MAX_TEMP);

        display.print(F("Fake temp: "));
        display.print(sensorTemp);
        display.print((char)247); // ° degree symbol
        display.println(F("C"));
    }
    else
    {
        // Use BME temperature sensor
        sensorTemp = bme.temperature;
    }

    if (tempFlash)
    {
        int tempPos = mapC(sensorTemp, MIN_TEMP, MAX_TEMP, 0, NUM_LEDS - tempWidth);

        for (int i = 0; i < tempWidth; i++)
        {
            leds[tempPos + i] = CRGB::Black;
        }
    }

    FastLED.show();
}
