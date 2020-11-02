/* 2_58.c the program for is_little_endian */
#include <stdio.h>

typedef unsigned char *byte_pointer;

int main() {
    int test_num = 0xff;
    byte_pointer start = (byte_pointer) &test_num;
    if (start[0] == 0xff) /* little endian */
        printf("1\n");
        return 1;
    printf("0\n");
    return 0;
}