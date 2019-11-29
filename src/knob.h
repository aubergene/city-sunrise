const int knobNumReadings = 16;   // number of readings to average
const int knobPin = A0;           // select the input pin for the potentiometer
const int knobReadFrequency = 50; // read every X milliseconds
int knobValue = 0;                    // variable to store the value coming from the sensor
int knobValues[knobNumReadings];  // array to store readings
int knobIndex = 0;                // variable to store our position in the array
int knobLastReadMillis = 0;       // variable to store our position in the array

void setup_knob()
{
    for (int i = 0; i < knobNumReadings; i++)
    {
        knobValues[i] = 0;
    }
}

void loop_knob()
{
    if (knobLastReadMillis < millis() - knobReadFrequency)
    {
        // knobValue = analogRead(knobPin);
        knobValues[knobIndex++] = analogRead(knobPin);
        if (knobIndex >= knobNumReadings)
        {
            knobIndex = 0;
        }

        int knobSum = 0;
        for (int i = 0; i < knobNumReadings; i++)
        {
            knobSum += knobValues[i];
            // Serial.print(knobValues[i]);
            // Serial.print(" ");
        }
        knobValue = knobSum / knobNumReadings;

        knobValue = map(knobValue, 200, 1000, 0, 255);
        knobValue = constrain(knobValue, 0, 255);

        // Serial.print("\t val:");
        // Serial.println(knobValue);
    }
}
