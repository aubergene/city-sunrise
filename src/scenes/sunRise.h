void sunRise(int t)
{
    const int mid = NUM_LEDS / 2;

    int n = map(t, 0, 255, 0, mid);
    n = constrain(n, 0, mid);

    display.print(F("Knob value: "));
    display.println(n);
    display.display();

    FastLED.clear();

    for (int i = 0; i < n; i++)
    {
        leds[mid - i] = CRGB::Red;
        leds[mid + i] = CRGB::Green;
    }

    FastLED.show();


    // This is kind of a hack
    // This scene is blocking and so when it ends I switch to the next
    // scene and reset the timer.
    // I wouldn't do it this way if I knew a better way :/
    // scene++;
    // startedScene += sceneLen;
}
