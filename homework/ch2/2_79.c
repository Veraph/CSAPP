# include <stdio.h>
# include <assert.h>
# include <limits.h>

/*
 * function that computes 3 * x / 4
 */
int mul3div4(int x) {
    /* do not bother the overflow situation */

    int mask = INT_MIN;
    int res = x + (x << 1);
    /* now deal with rounding down or up */
    (res & mask) && (res += (1 << 2) - 1);

    return res >> 2;
}

int main() {
    assert(mul3div4(0x1234) == 3 * 0x1234 / 4);
    assert(mul3div4(INT_MAX) == 3 * INT_MAX / 4);
    assert(mul3div4(INT_MIN) == 3 * INT_MIN / 4);
    assert(mul3div4(-0x1234) == 3 * -0x1234 / 4);

    return 0;
}
    
