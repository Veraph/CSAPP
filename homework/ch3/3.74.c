#include <stdio.h>
#include <assert.h>

/* using conditional move
 */

typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range(float x) {
    __asm__(
        "vxorps %xmm1, %xmm1, %xmm1\n\t"
        "movq $1, %rax\n\t"
        "movq $2, %r8\n\t"
        "movq $0, %r9\n\t"
        "movq $3, %r10\n\t"
        "vucomiss %xmm1, %xmm0\n\t"
        "cmovaq %r8, %rax\n\t"
        "cmovbq %r9, %rax\n\t"
        "cmovpq %r10, %rax\n\t"
        );
}

int main() {
    range_t n = NEG, z = ZERO, p = POS, o = OTHER;
    assert(n == find_range(-1.2));
    assert(z == find_range(0.0));
    assert(p == find_range(1.3));
    assert(o == find_range(0.0/0.0));

    return 0;
}
