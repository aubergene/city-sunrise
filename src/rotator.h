/* Author: Danny van den Brande, Arduinosensors.nl
 This is a example on how to use the KY-040 Rotary encoder.
 Its very basic but if your new to arduino or could not find
 any code, then you have something to start with.
 because there is little documentation about the KY sensor kit.
 */
int CLK = 3; // Pin 9 to clk on encoder
int DT = 2;  // Pin 8 to DT on encoder

int RotPosition = 0;
int rotation;
int value;
boolean LeftRight;

void setup_rotator()
{
    pinMode(CLK, INPUT);
    pinMode(DT, INPUT);
    rotation = digitalRead(CLK);
}
void loop_rotator()
{
    value = digitalRead(CLK);
    if (value != rotation)
    { // we use the DT pin to find out which way we turning.
        if (digitalRead(DT) != value)
        { // Clockwise
            RotPosition++;
            LeftRight = true;
        }
        else
        { //Counterclockwise
            LeftRight = false;
            RotPosition--;
        }
    }
    rotation = value;
}
