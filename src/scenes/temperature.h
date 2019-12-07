void temperature()
{
    loop_bme680();

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

    FastLED.clear();

    int sat = 255;
    int val = 200;

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
        val = sin8(i * 1.4);
        int x = p1 - margin + i;
        leds[x] += CHSV(72, sat, gamma8[val]);
    }

    FastLED.show();
}
