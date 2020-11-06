# include <stdio.h>
# include <assert.h>

typedef unsigned float_bits;

/* Example that will return 0 if f is denorm */
float_bits float_denorm_zero(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    !exp && (frac = 0);
    
    /* reassemble bits */
    return (sign << 31) | (exp << 23) | frac;
}

/* compute -f.
 * if f is NaN, return f.
 */
float_bits float_negate(float_bits f) {
    unsigned exp = f >> 23 & 0xFF;

    float_bits ans = -f;
    (exp == 0xFF) && (ans = f);

    return ans;
}

int main() {
    assert(float_negate(0x12345678) == -0x12345678);
    assert(float_negate(0xFFFFFFFF) == 0xFFFFFFFF);

    return 0;
}
