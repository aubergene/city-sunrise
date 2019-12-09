![](analysis/city-sunrise.jpg)

# City Sunrise

A project to create an ambient interface to show various environmental data.

## Parts list

- Adafruit Metro M0
- Adafruit BME680 Sensor - temperature, humidity, air pressure, VOC
- SSD1306 Monochrome OLED screen, 128x32 pixels
- WS2811 "NeoPixel" rope 300 pixels
- HW-040 Rotary encoder and switch
- 1000µF 6.3V capacitor
- 5V 2A DC power supply

## Libraries

- FastLED - https://github.com/FastLED/FastLED
- TFT - https://www.arduino.cc/en/Reference/TFTLibrary
- Adafruit BME680  - https://github.com/adafruit/Adafruit_BME680
- Adafruit SSD1306 - https://github.com/adafruit/Adafruit_SSD1306

## Notes

- Powering neopixels using levelshifter for 3.3 -> 5v https://learn.adafruit.com/neopixel-levelshifter
