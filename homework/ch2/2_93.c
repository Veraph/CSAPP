# include <stdio.h>
# include <assert.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    sig && (sig = 0);
    if (exp == 0xFF)
        return f;

    return sig << 31 | exp << 23 | frac;
}

int main() {
    assert(float_absval(0x12345678) == 0x12345678);
    assert(float_absval(0x82345678) == 0x02345678);
    assert(float_absval(0xFFFFFFFF) == 0xFFFFFFFF);
    return 0;
}
