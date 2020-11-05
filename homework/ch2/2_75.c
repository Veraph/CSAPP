# include <stdio.h>
# include <assert.h>
# include <inttypes.h>

/* use prod function of int
 * to write prod function of unsigned
 */
int signed_high_prod(int x, int y) {
    int64_t mul = (int64_t) x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    uint64_t mul = (uint64_t) x * y;
    return mul >> 32;
}

unsigned high_prod_from_signed(unsigned x, unsigned y) {
    int sig_x = x >> 31;
    int sig_y = x >> 31;

    /* x and y be implicit transfer to int */
    int signed_prod = signed_high_prod(x, y);
    /* we drop the sig_x * sig_y because it has the 2^64 as
     * prod part(sig_x * sig_y) << 64
     * which will be droped as the precision of 64-bit
     * is 0 to 63
     */
    return signed_prod + x * sig_y + y * sig_x;
}

int main() {
    unsigned x = 0x12345678;
    unsigned y = 0x23456789;

    assert(unsigned_high_prod(x, y) == high_prod_from_signed(x, y));

    return 0;
}
