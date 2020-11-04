# include <stdio.h>
# include <assert.h>

/* Declaration of data type where 4 bytes
 * are packed into an unsigned
 */
typedef unsigned packed_t;

/* Extract bytei(numbered byte num)  from word
 * return as signed integer
 */
int xbyte(packed_t word, int bytenum) {
    /* for instance 0x00112233, bytenum = 2
     * then we have to extract the 0x11 */
    int w = sizeof(unsigned);
    int shift_left = (w - 1 - bytenum) << 3;
    int shift_right = (w - 1) << 3;
    return (int) word << shift_left >> shift_right;
}

int main() {
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA);
    assert(xbyte(0x00112233, 2) == 0x11);

    return 0;
}
