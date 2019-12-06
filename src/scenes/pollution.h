void pollution(int amount)
{
    display.print(F("Knob value: "));
    display.println(amount);
    // display.display();

    fadeToBlackBy(leds, NUM_LEDS, 20);

    for (int i = 0; i < NUM_LEDS; i++)
    {
        if (random16() < amount)
        {
            leds[i] += CRGB::Purple;
        }
    }

    FastLED.show();
}
