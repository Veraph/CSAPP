# include <stdio.h>
# include <assert.h>

int generator_A(int k) {
    /* generate the bit patterns like
     * 1^w-k 0^k
     */
    int base = ~0;
    return base << k;
}

int generator_B(int k, int j) {
    /* generate the bit patterns like
     * 0^w-k-j 1^k 0^j
     * 
     * better method
     * just simple return ~generator_A(k) << j
     */
    int base = ~0;
    return (base << j) ^ (base << (k + j));
}

int main() {
    assert(generator_A(8) == 0xFFFFFF00);
    assert(generator_B(4, 4) == 0x000000F0);

    return 0;
}
