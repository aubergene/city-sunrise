void openCurtains()
{
    const int mid = (NUM_LEDS - 1) / 2;
    const int width = 10;

    for (int i = 0; i < mid; i++)
    {
        FastLED.clear();
        leds[mid - i] = CRGB::WhiteSmoke;
        leds[mid + i] = CRGB::WhiteSmoke;
        FastLED.show();
    }
}
