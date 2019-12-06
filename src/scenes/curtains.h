void openCurtains()
{
    int mid = NUM_LEDS / 2;

    for (int i = 0; i < mid; i++)
    {
        FastLED.clear();
        leds[mid - i] = CRGB::WhiteSmoke;
        leds[mid + i] = CRGB::WhiteSmoke;
        FastLED.show();
    }
}
