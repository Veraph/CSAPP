# include <stdio.h>
# include <assert.h>

/* bad code which does not run
 * properly on some machines */
int bad_int_size_is_32() {
    /* set most significant bit of 32-bit machine */
    int set_msb = 1 << 31;
    /* shift 32-bit word */
    int beyond_msb = 1 << 32; /* this will have a value undefined. */

    return set_msb && !beyond_msb;
}

/* the right one which can
 * run on a 32-bit machine */
int int_size_is_32() {
    int set_msb = 1 << 31;

    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

/* the right one which can
 * run on a 16-bit machine */
int int_size_is_32_for_16() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int main() {
    assert(int_size_is_32());
    assert(int_size_is_32_for_16());
    return 0;
}
