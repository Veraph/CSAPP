# include <stdio.h>
# include <assert.h>
# include <limits.h>

/* Determine whether arguments can be
 * subtracted without overflow
 */
int tsub_ok(int x, int y) {
    /* transfer x - y to x + (-y)
     * then we can use the method
     * of addition
     */
    int res = x - y;
    /* two situation can cause over flow
     * 1. x < 0 and -y < 0 but res >= 0
     * 2. x > 0 and -y > 0 but res < 0
     */
    int tsub_mask = INT_MIN;
    
    int pos_over = !(x & tsub_mask) && !(-y & tsub_mask) && (res & tsub_mask);
    int neg_over = (x & tsub_mask) && (-y & tsub_mask) && !(res & tsub_mask);

    return !pos_over && !neg_over;
}

int main() {
    assert(!tsub_ok(INT_MAX, -0x123));
    assert(!tsub_ok(INT_MIN, 0x123));
    assert(tsub_ok(0x123, 0x234));

    return 0;
}
