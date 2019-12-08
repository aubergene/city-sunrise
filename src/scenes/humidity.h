const int MIN_HUMIDITY = 30;
const int MAX_HUMIDITY = 50;

void humidity()
{
    display.print(F("Humidity: "));
    display.print(bme.humidity);
    display.println(F("%"));

    const int MIN_ROT = -30;
    const int MAX_ROT = 30;

    rotPos = constrain(rotPos, MIN_ROT, MAX_ROT);
    int sensorHumidity;

    if (fakeSensor)
    {
        sensorHumidity = mapC(rotPos, MIN_ROT, MAX_ROT, MIN_HUMIDITY, MAX_HUMIDITY);
        display.print(F("Fake humidity: "));
        display.print(sensorHumidity);
        display.println(F("%"));
    }
    else
    {
        sensorHumidity = bme.humidity;
    }

    FastLED.clear();

    int speed = mapC(sensorHumidity, MIN_HUMIDITY, MAX_HUMIDITY, 40, 20);

    uint8_t ms = millis() / speed;

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
}
