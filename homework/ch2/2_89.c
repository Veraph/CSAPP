# include <stdio.h>
# include <assert.h>
# include <limits.h>

int main() {
    int x = 0x64e73387;
    int y = 0xd31cb264;
    int z = 0xd22f1fcd;

    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;

    assert((dx * dy) * dz == dx * (dy * dz));

    return 0;
}
