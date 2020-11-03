# include <stdio.h>
# include <assert.h>

/* return 1 when any odd bit of x equals 1, 0 otherwise */
int any_odd_one(unsigned x) {
    return !(0xAAAAAAAA & x);
}

int main() {
    assert(!any_odd_one(0x2));
    assert(any_odd_one(0x4));
    return 0;
}

