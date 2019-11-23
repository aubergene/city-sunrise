void fade(int start, int end, int amount=250)
{
    for (int i = start; i < end; i++)
    {
        leds[i].fadeToBlackBy(250);
    }
}
