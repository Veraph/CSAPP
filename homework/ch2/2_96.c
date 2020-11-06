# include <stdio.h>
# include <assert.h>

typedef unsigned float_bits;

/* compute (int) f
 * if conversion causes overflow or f is NaN
 * return 0x80000000
 */

int float_f2i(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 0x7f;
    int num;

    if (exp >= 0 && exp < bias) {
        /* number less than 1 */
        return 0;
    } else if (exp >= 31 + bias) {
        /* overflow */
        return 0x80000000;
    } else {
        unsigned E = exp - bias;
        /* add the missing bit */
        unsigned M = frac | 0x800000; /* M = 1 + f */
        if (E > 23)
            /* we need more left shift */
            num = M << (E - 23);
        else
            /* too much left shift
             * we should shift it back
             */
            num = M >> (23 - E);
    }

    return sign ? -num : num;
}
