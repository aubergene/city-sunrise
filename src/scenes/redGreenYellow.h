void redGreenYellow()
{
    FastLED.clear();
    for (int i = 0; i < NUM_LEDS; i++)
    {
        uint8_t ms = millis() / 40;
        uint8_t val = cubicwave8(ms + i * 8);
        leds[i].r = scale8(gamma8[val], 180);

        val = cubicwave8(ms + i * 12);
        leds[i].g = gamma8[val];
    }

    FastLED.show();
    delay(50);
}
