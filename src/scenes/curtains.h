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

    // This is kind of a hack
    // This scene is blocking and so when it ends I switch to the next
    // scene and reset the timer.
    // I wouldn't do it this way if I knew a better way :/
    // scene++;
    // startedScene += sceneLen;
}
