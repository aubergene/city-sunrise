// map and constrain
long mapC(long n, long domainLow, long domainHigh, long rangeLow, long rangeHigh, bool clamp=true) {
    long val = map(n, domainLow, domainHigh, rangeLow, rangeHigh);
    if (clamp) {
        if (rangeLow > rangeHigh) {
            long swapTmp = rangeLow;
            rangeLow = rangeHigh;
            rangeHigh = swapTmp;
        }
        val = constrain(val, rangeLow, rangeHigh);
    }
    return val;
}
