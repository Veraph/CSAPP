# include <stdio.h>
# include <assert.h>

typedef unsigned float_bits;

/* we need a function to calculate
 * the highest bit of int i
 */
int bit_length(int i) {
    if (i & INT_MIN)
        return 32;
    
    unsigned u = (unsigned) i;
    int len = 0;
    while (u >= (1 << len))
        len++;

    return len;
}

/* we also need a mask function
 * to create mask to avoid any information
 * beyond the bit_length
 */
unsigned bit_mask(int l) {
    return (unsigned) -1 >> (32 - l);
}



/* compute (float) i */
float_bits float_i2f(int i) {
    unsigned sig, exp, frac, rest, exc_sig, round_part;
    unsigned bits, fbits;
    unsigned bias = 0x7F;

    if (i == 0) {
        sig = 0;
        frac = 0;
        exp = 0;
        return sig << 31 | exp << 23 | frac;
    }

    if (i == INT_MIN) {
        sig = 1;
        exp = bias + 31;
        frac = 0;
        return sig << 31 | exp << 23 | frac;
    }

    sig = 0;
    if (i < 0) {
        sig = 1;
        i = -i;
    }

    bits = bit_length(i);
    fbits = bits - 1;
    exp = bias + fbits;

    rest = i & bit_mask(fbits);
    if (fbits <= 23) {
        frac = rest << (23 - fbits);
        exc_sig = exp << 23 | frac;
    } else {
        int offset = fbits - 23;
        /* too many that cannot be stored
         * in the 23 bits of float number
         */
        int round_mid = 1 << (offset - 1);

        /* get the part which will be round */
        round_part = rest & bit_mask(offset);
        frac = rest >> offset;
        exc_sig = exp << 23 | frac;

        if (round_part > round_mid)
            exc_sig++;
        else if (round_part == round_mid) {
            if (frac & 0x1)
                exc_sig++;
        }

    }

    return sig << 31 | exc_sig;
}


















    unsigned sign = i & INT_MIN;
    unsigned 
