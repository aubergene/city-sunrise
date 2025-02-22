#include <FastLED.h>
#include "./gamma8.h"

// How many leds in your strip?
#define NUM_LEDS 300
#define COLOR_ORDER GRB
#define LED_TYPE WS2811
#define LED_PIN 9

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup_leds()
{
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    LEDS.setBrightness(255);

    FastLED.clear();
    FastLED.show();
}
