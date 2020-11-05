# include <stdio.h>
# include <assert.h>
# include <limits.h>

/* Divide by power of 2
 * assume 0 <= k < w - 1
 */
int divide_power2(int x, int k) {
    /* calculate x / 2^k
     * we should be careful
     * about the situation when
     * x is negative
     */
    int is_neg = x & INT_MIN;
    /* deal with x when is_neg
     * that is, we have to apply
     * the rounding up when x is_neg
     * otherwise, simple rounding down
     */
    is_neg && (x = x + (1 << k) - 1);
    return x >> k;
}

int main() {
    int x = 0x80000006;
    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);

    return 0;
}
