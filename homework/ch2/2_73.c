# include <stdio.h>
# include <assert.h>
# include <limits.h>

/* addition that saturates to TMin or TMax */
int saturating_add(int x, int y) {
   /* review, the Tmax is 0x7FFFF...
    * and the Tmin is 0x80000..
    */
    int sum = x + y;
    int sat_mask = INT_MIN;

    /* the key point is
     * if x > 0, y > 0; but sum < 0, then it is positive overflow
     * if x < 0, y < 0; but sum >= 0, then it is negtive overflow
     */
    int pos_over = !(x & sat_mask) && !(y & sat_mask) && (sum & sat_mask);
    int neg_over = (x & sat_mask) && (y & sat_mask) && !(sum & sat_mask);

    /* assign the sum based on pos_over and neg_over */
    (pos_over && (sum = INT_MAX)) || (neg_over && (sum = INT_MIN));

    return sum;
}

int main() {
    assert(saturating_add(INT_MAX, 0x123) == INT_MAX);
    assert(saturating_add(INT_MIN, -0x123) == INT_MIN);
    assert(saturating_add(0x123, 0x234) == 0x123 + 0x234);

    return 0;
}
