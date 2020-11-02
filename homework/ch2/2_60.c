#include <stdio.h>
#include <assert.h>

unsigned replace_byte (unsigned x, int i,  unsigned char b) {
    /* every significant bytes have 8 bits, hence i << 3(which equals *3) */
    unsigned mask = ((unsigned) 0xFF << (i << 3));
    unsigned add_item = ((unsigned) b << (i << 3));

    return (x & ~mask) | add_item;

}

int main() {
    unsigned x = 0x12345678;
    int i = 2;
    unsigned char b = 0xAB;
    assert(replace_byte(x, i, b) == 0x12AB5678);
    return 0;
}