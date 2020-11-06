# include <stdio.h>
# include <assert.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF)
        return f;

    /* introduce a addition to help us do the rounding */
    int addition = (frac & 0x3) == 0x3;

    if (exp == 0) {
        frac >>= 1;
        frac += addition;
    } else if (exp == 1) {
        /* from normalized to denormalized */
        unsigned res = f & 0x7FFFFFFF;
        res >>= 1;
        exp = res >> 23 & 0xFF;
        frac = res & 0x7FFFFF;
    } else
        exp -= 1;

    return sig << 31 | exp << 23 | frac;
}

