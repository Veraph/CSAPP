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

    printf("x: %i; dx: %f\n", x, dx);
    printf("y: %i; dy: %f\n", y, dy);
    printf("z: %i; dz: %f\n", z, dz);
    
    double dx_y_z = (dx * dy) * dz;
    double dx_z_y = (dx * dz) * dy;

    printf("dx_y_z: %f; dx_z_y: %f\n", dx_y_z, dx_z_y);
    
    printf("dxy based on dx_y_z: %f\n", dx_y_z / dz);
    printf("dxy based on dx_z_y: %f\n", dx_z_y / dz);

    return 0;
}

