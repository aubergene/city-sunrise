void temperature()
{
    display.print(F("Temperature: "));
    display.print(bme.temperature);
    display.print((char)247);
    display.println(F("C"));

    // display.print("Pressure: ");
    // display.print(bme.pressure / 100.0);
    // display.println(" hPa");

    // display.print("Humidity: ");
    // display.print(bme.humidity);
    // display.println(" %");

    // display.print("Gas: ");
    // display.print(bme.gas_resistance / 1000.0);
    // display.println(" KOhms");

    // display.display();

    int hue;
    int breakPoint = NUM_LEDS / 3;

    FastLED.clear();

    int sat = 255;
    int val = 200;

    int freezePoint = 120;

    fill_gradient(leds, 0, CHSV(160, sat, val), freezePoint, CHSV(142, sat, val), SHORTEST_HUES);
    fill_gradient(leds, freezePoint, CHSV(72, sat, val), NUM_LEDS-1, CHSV(0, sat, val), SHORTEST_HUES);

    // for (int i = freezePoint - 50; i < freezePoint + 100; i++)
    // {
    //     leds[i].fadeLightBy(i * 2);
    // }

    // for (int i = freezePoint - 50; i < freezePoint + 100; i++)
    // {
    //     // int v = freezePoint - abs(freezePoint -i);
    //     leds[i] += CHSV(72, sat, 100);
    // }

    // for (int i = 0; i < NUM_LEDS; i++)
    // {
    //     int v = mapC(i, 0, NUM_LEDS/3, 255, 0);
    //     leds[i] += CHSV(170, 200, v);

    //     v = mapC(i, NUM_LEDS/3, NUM_LEDS, 0, 255);
    //     leds[i] += CHSV(42, 200, v);

    //     v = mapC(i, NUM_LEDS/2, NUM_LEDS, 0, 255);
    //     leds[i] += CHSV(0, 200, v);
    // }

    FastLED.show();
}
