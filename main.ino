#include <FastLED.h>

#include "src/gamma8.h"

// How many leds in your strip?
#define NUM_LEDS 300
#define COLOR_ORDER GRB
#define LED_TYPE WS2811
#define LED_PIN 9

// Define the array of leds
CRGB leds[NUM_LEDS];

int pos = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("resetting");
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    LEDS.setBrightness(90);
}

void fadeall()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i].fadeToBlackBy(250);
    }
}

void loop()
{
    // redGreenYellow();
    seaWaves();
}

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