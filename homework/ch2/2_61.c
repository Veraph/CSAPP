# include <stdio.h>

/* assert any bit of x equals 1 */
int all_one (int x) {
    /* do the xor operation between x and all 1 */
    /* if any bit in x equals 1, return 0 */
    /* return x ^ (~x | x); */

    /* right way */
    return !(~x);
}

/* assert any bit of x equals 0 */
int all_zero(int x) {
    /* do the xor operation again, but use & in the second step */
    /* return x ^ (~x & x); */

    /* right way */
    return !x;
}

/* assert any bit in the least significant byte of x equals 1 */
int least_one(int x) {
    /* first take out the least significant part */
    /* and then do the xor with all 1s' if all 1, will have zero */
    /* return (x & 0xFF) ^ 0xFF; */

    /* right way */
    return !~(x | ~0xFF);
}

/* assert any bit in the most significant byte of x equals 0 */
int most_zero(int x) {
    /* calculate the shift needed to get the most significant byte */
    int shift_val = (sizeof(int) - 1) << 3;
    /* do the arithmetic shift to get the most significant byte */
    int xright = x >> shift_val;
    /* take the most significant byte and the do calculation */
    /* return (x & 0xFF) ^ 0x00; */

    /* right way */
    return !(xright & 0xFF);


}

int main() {
    /* although I set x to be 0xff, but the actual value
    will be 0x000..ff due to the avaliable scale of int */
    int x = 0xff;
    int ans1 = all_one(x);
    int ans2 = all_zero(x);
    int ans3 = least_one(x);
    int ans4 = most_zero(x);

    printf("%i %i %i %i\n", ans1, ans2, ans3, ans4);
    return 0;
}



