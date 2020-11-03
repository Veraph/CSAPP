# include <stdio.h>
# include <assert.h>

/* return 1 when x contines odd number of 1s, 0 other wise, */
int odd_ones(unsigned x) {
    /* every step we will check the bit is 1 or 0 using xor
     * the bits we checked will increased as 1, 2, 4, 8, 16
     */
    x ^= x >> 1;
    x ^= x >> 2;
    x ^= x >> 4;
    x ^= x >> 8;
    x ^= x >> 16;
    /* only return the first bit which store all 1 situation. */
    x &= 1;
    return x;
}

int main() {
    assert(!odd_ones(0x10101010));
    assert(odd_ones(0x10101011));
    return 0;
}
