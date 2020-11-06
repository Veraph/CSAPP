# include <stdio.h>
# include <assert.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF)
        return f;

    /* when do the multiplication
     * should deal with when it is
     * denormlized;
     * when too many 1 in exp part
     * and when it is normal
     */
    if (!exp)
        frac <<= 1;
    else if (exp == 0xFF - 1) {
        exp = 0xFF;
        frac = 0;
    } else
        exp += 1;

    return sign << 31 | exp << 23 | frac;
}

int main() {
    float test = 0x12345678;
    /* how to assert this? */
    assert(float_twice(0x12345678) == (float_bits) 0x12345678 * 2.0);
    assert(float_twice(0xFFFFFFFF) == 0xFFFFFFFF);

    return 0;
}
