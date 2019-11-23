void seaWaves()
{
    FastLED.clear();
    uint8_t ms = millis() / 40;
    for (int i = 0; i < NUM_LEDS; i++)
    {
        uint8_t val = cubicwave8(ms + i * 8);
        leds[i].b = gamma8[scale8(val, 30)];

        val = cubicwave8(ms + i * 4);
        leds[i].g = gamma8[64 + scale8(val, 64)];

        val = cubicwave8(ms + i * 2);
        leds[i].b = gamma8[96 + scale8(val, 64)];
    }

    FastLED.show();
    delay(20);
}
