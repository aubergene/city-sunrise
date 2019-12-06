void sunRise(int sun)
{
    const int mid = NUM_LEDS / 2;

    int n = map(sun, 0, 255, 0, mid);
    n = constrain(n, 0, mid);

    FastLED.clear();
    int h, v;

    // Add to overall brightness as sunrise grows
    int maxV = map(n, 0, mid, 0, 50);

    display.print(F("sun: "));
    display.println(sun);

    display.print(F("n: "));
    display.println(n);

    display.print(F("maxV: "));
    display.println(maxV);

    // display.display();

    // Add to overall brightness as sunrise grows
    // const int skyBlue = 168;
    // int skyV = map(n, 0, mid, 150, 0);

    // for (int i = 0; i < mid; i++) {
    //     leds[mid + i] = CHSV(skyBlue, 200, gamma8[skyV]);
    //     leds[mid - i] = CHSV(skyBlue, 200, gamma8[skyV]);
    // }

    for (int i = 0; i < n; i++)
    {
        h = map(i, 0, mid, 5, 60);
        v = maxV + map(i, 0, mid, 200, 100);
        leds[mid - i] += CHSV(h, 200, gamma8[v]);
        leds[mid + i] += CHSV(h, 200, gamma8[v]);
    }

    FastLED.show();
}
