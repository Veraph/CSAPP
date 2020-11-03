# include <stdio.h>
# include <assert.h>

/* use arithmetic right shift to perform
a logical(most significant bit fill with 0) right shift */
unsigned srl(unsigned x, int k) {
    /* perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    
    /* calculate how many bits in int type */
    int w = sizeof(int) << 3;

    /* generate a mask to help us */
    int mask = -1 << (w - k);

    return xsra & (~mask);

}

/* use logical right shift to perform a arithmetic
right shift */
int sra(int x, int k) {
    /* perform shift logically */
    int xsrl = (unsigned) x >> k;

    int w = sizeof(int) << 3;

    int mask = -1 << (w - k);

    int m = -1 << (w - 1); /* like 0x1000 */
    /* let the mask remain unchanged when the first bit of x is 1(do & operation with 1)
    otherwise the mask change to 0 (do & operation with 0) */
    mask &= !((x & m) - 1); /* if the first bit of x is 1, then the (x & m) will be 1 */

    return xsrl | mask;
}

int main() {
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    return 0;
}
