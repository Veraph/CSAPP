/* function which yield a word consisting 
of the least significant byte of x and
remaining bytes of y */
#include <stdio.h>
#include <assert.h>

int main() {
    /* the trick is to use the mask */
    size_t mask = 0xff;
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;

    size_t res = (x & mask) | (y & ~mask);
    assert(res == 0x765432EF);
    return 0;

}