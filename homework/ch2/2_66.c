# include <stdio.h>
# include <assert.h>

/* generate mask indicating leftmosr 1 in x.
 * assume w = 32.
 */
int left_most_one(unsigned x) {
    /* first transform the
     * x into [000...111]
     * the x0 has done the |
     * operation with all bit
     * and the x31 has done 
     * the | operation with none
     * hence the first 1 is the 
     * highest bit */
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}

int main() {
    assert(left_most_one(0xff00) == 0x8000);
    assert(left_most_one(0x6600) == 0x4000);
    return 0;
}
