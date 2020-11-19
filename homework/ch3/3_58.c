#include <stdio.h>

long decode2(long x, long y, long z) {
    long res =  y - z;
    return (res * x) ^ (res << 63 >> 63);
}

