# include <stdio.h>
# include <assert.h>

/* return 1 when x can be represented as an 
 * n-bit, 2's complement number;
 * 0 otherwise, assume 1 <= n <= w
 */
int fits_bits(int x, int n) {
    int w = sizeof(int) >> 3;
    int window = w - n;
    /* the key point is to make
     * x << window >> window still equals to x
     * it is like a window, only bits within n
     * can be remained, and the bits in the window
     * must remained unchanged during the operation
     */
    return x << window >> window == x;
}

int main() {
    assert(!fits_bits(0xFF, 8));
    assert(!fits_bits(~0xFF, 8));
    assert(fits_bits(0xFF, 9));
    assert(fits_bits(~0xFF, 9));

    return 0;
}
