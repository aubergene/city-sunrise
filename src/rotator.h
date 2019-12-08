/* Arduino New Rotary Encoder Debounce

Created by Yvan / https://Brainy-Bits.com

This code is in the public domain...

You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!

*/

// Rotary Encoder Module connections
const int PinDT = 2;  // DATA signal
const int PinCLK = 3; // CLOCK signal

// Variables to debounce Rotary Encoder
long TimeOfLastDebounce = 0;
int DelayofDebounce = 0.01;

// Store previous Pins state
int PreviousCLK;
int PreviousDATA;

int rotPos = 0; // Store current counter value

void setup_rotator()
{
    pinMode(PinCLK, INPUT);
    pinMode(PinDT, INPUT);

    // Put current pins state in variables
    PreviousCLK = digitalRead(PinCLK);
    PreviousDATA = digitalRead(PinDT);
}

// Check if Rotary Encoder was moved
void check_rotary()
{
    if ((PreviousCLK == 0) && (PreviousDATA == 1))
    {
        if ((digitalRead(PinCLK) == 1) && (digitalRead(PinDT) == 0))
        {
            rotPos++;
        }
        if ((digitalRead(PinCLK) == 1) && (digitalRead(PinDT) == 1))
        {
            rotPos--;
        }
    }

    if ((PreviousCLK == 1) && (PreviousDATA == 0))
    {
        if ((digitalRead(PinCLK) == 0) && (digitalRead(PinDT) == 1))
        {
            rotPos++;
        }
        if ((digitalRead(PinCLK) == 0) && (digitalRead(PinDT) == 0))
        {
            rotPos--;
        }
    }

    if ((PreviousCLK == 1) && (PreviousDATA == 1))
    {
        if ((digitalRead(PinCLK) == 0) && (digitalRead(PinDT) == 1))
        {
            rotPos++;
        }
        if ((digitalRead(PinCLK) == 0) && (digitalRead(PinDT) == 0))
        {
            rotPos--;
        }
    }

    if ((PreviousCLK == 0) && (PreviousDATA == 0))
    {
        if ((digitalRead(PinCLK) == 1) && (digitalRead(PinDT) == 0))
        {
            rotPos++;
        }
        if ((digitalRead(PinCLK) == 1) && (digitalRead(PinDT) == 1))
        {
            rotPos--;
        }
    }
}

void loop_rotator()
{
    // If enough time has passed check the rotary encoder
    if ((millis() - TimeOfLastDebounce) > DelayofDebounce)
    {
        check_rotary(); // Rotary Encoder check routine below

        PreviousCLK = digitalRead(PinCLK);
        PreviousDATA = digitalRead(PinDT);

        TimeOfLastDebounce = millis(); // Set variable to current millis() timer
    }
}