# include <stdio.h>
# include <assert.h>
# define VA 0x12345678

/* do rotating left shift. assume 0 <= n < w
 * example when x = 0x12345678 and w = 32:
 * n = 4 --> 0x23456781, n = 20 --> 0x67812345
 */
unsigned rotate_left(unsigned x, int n) {
    /* calculate the bit length of unsigned */
    int w = sizeof(unsigned) << 3;
    /* pay attention to when n = 0,
     * as the w - n will become the
     * word size which will have undefiend error */
    return x << n | x >> (w - n - 1) >> 1;
}

int main() {
    assert(rotate_left(VA, 4) == 0x23456781);
    assert(rotate_left(VA, 20) == 0x67812345);
    /* the n = 0 case should be noticed */
    assert(rotate_left(VA, 0) == 0x12345678);

    return 0;
}
