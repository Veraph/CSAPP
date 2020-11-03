# include <stdio.h>

int int_shifts_are_arithmetic() {
    /* test with the value -1 as shifts will
    not influence this val */
    return ~0 == (~0 >> 1);

    /* without == */
    int x = -1;
    return !(x ^ (x >> 1));
}

int main() {
    int ans = int_shifts_are_arithmetic();

    printf("%i\n", ans);
    return 0;
}

