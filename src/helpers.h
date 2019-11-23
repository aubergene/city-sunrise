void fadeall(int amount=250)
{
    fade(start, end, amount);
}

void fade(int start, int end, int amount=250)
{
    for (int i = start; i < end; i++)
    {
        leds[i].fadeToBlackBy(250);
    }
}

