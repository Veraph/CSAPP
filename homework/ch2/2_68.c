# include <stdio.h>
# include <assert.h>

/* mask with least significant n bits set to 1
 * Examples: n = 6 -- > 0x3F, n = 17 -- > 0x1FFFF
 * assume 1 <= n <= w
 */
int lower_one_mask(int n) {
    /* calculate the bits of int */
    int w = sizeof(int) << 3;
    /* do the shift.
     * both ~0 and -1 is the same
     */
    return (unsigned) ~0 >> (w - n); /* take the maximum int using -1 and then using unsigned to cast */
}

int main() {
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);

    return 0;
}



