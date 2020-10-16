# include <stdio.h>
# include <math.h>

int main(){
    /* because of precision, the float answer of 1.0e20 is actually rounded, hence + 1.0 also is the rounded answer*/
    float f = 1.0e20;
    double d = 2.0;
    printf("%f\n", d + f - f);
    printf("%f\n", f - f + d);
}
x