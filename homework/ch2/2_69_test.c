# include <stdio.h>

int main() {
    int w = sizeof(unsigned) << 3;
    unsigned x = (0x12345678 << 0) + (0x12345678 >> (w - 0));
    printf("%u", x);
    return 0;
}
