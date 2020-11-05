# include <stdio.h>
# include <assert.h>
# include <limits.h>

int threefourths(int x) {
    /* the key point is to
     * divide the x into r and l
     * parts, representing first 30
     * and last 2 bits respectively
     * and do r / 4 * 3 and l * 3 / 4
     * and do the sum
     */
    int r = x & ~0x3;
    int l = x & 0x3;

    int rd4 = r >> 2;
    int rd4m3 = rd4 + (rd4 << 1);

    int lm3 = l + (l << 1);
    (x & INT_MIN) && (lm3 += (1 << 2) - 1);
    int lm3d4 = lm3 >> 2;

    return rd4m3 + lm3d4;
}

int main() {
    assert(threefourths(8) == 6);
    assert(threefourths(9) == 6);
    assert(threefourths(10) == 7);
    assert(threefourths(11) == 8);
    assert(threefourths(12) == 9);

    assert(threefourths(-8) == -6);
    assert(threefourths(-9) == -6);
    assert(threefourths(-10) == -7);
    assert(threefourths(-11) == -8);
    assert(threefourths(-12) == -9);
    return 0;
}
