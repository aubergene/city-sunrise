#include <FastLED.h>
#include "src/gamma8.h"
#include "src/screen.h"

// How many leds in your strip?
#define NUM_LEDS 300
#define COLOR_ORDER GRB
#define LED_TYPE WS2811
#define LED_PIN 9
#define NUM_SCENES 4

// Define the array of leds
CRGB leds[NUM_LEDS];

int cursor = 0;
int scene = 0;
int startedScene = 0;
const int sceneLen = 2000;

const int buttonPin = 2; // the number of the pushbutton pin
int buttonState = 0; // variable for reading the pushbutton status
int buttonPushStart = 0;

const int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup()
{
    pinMode(buttonPin, INPUT);

    Serial.begin(9600);
    Serial.println("resetting");
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    LEDS.setBrightness(1200);

    screen_setup();

    display.setTextSize(1);              // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
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
    display.clearDisplay();
    display.setCursor(0, 0); // Start at top-left corner

    if (millis() > startedScene + sceneLen)
    {
        startedScene = millis();
        scene++;
        if (scene >= NUM_SCENES)
        {
            scene = 0;
        }
    }

    switch (scene)
    {
    case 0:
        display.println(F("openCurtains"));
        openCurtains();
        break;
    case 1:
        display.println(F("seaWaves"));
        seaWaves();
        break;
    case 2:
        display.println(F("bounceDot"));
        // bounceDot();
        break;
    case 3:
        display.println(F("redGreenYellow"));
        redGreenYellow();
        break;
    }

    display.println(millis());

    sensorValue = analogRead(sensorPin);
    display.println(sensorValue);

    buttonState = digitalRead(buttonPin);
    display.println(buttonState);

    // if (buttonState == HIGH && !buttonPushStart && buttonPushStart - millis() < 25) {
    //     buttonPushStart = millis();
    //     scene++;
    // }

    // if (buttonState == HIGH && !buttonPushStart && buttonPushStart - millis() < 25) {


    display.display();
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

void bounceDot()
{
    FastLED.clear();
    leds[cursor++] = CRGB::GhostWhite;
    FastLED.show();

    if (cursor >= NUM_LEDS)
        cursor = 0;
}

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
    scene++;
    startedScene += sceneLen;
}
