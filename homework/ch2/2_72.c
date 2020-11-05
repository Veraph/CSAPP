# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# include <string.h>

/* Copy integer into buffer if space is avaliable */
void copy_int(int val, void *buf, int maxbytes) {
    /* the condition cannot be 'maxbytes - sizeof(val) >= 0
     * as the sizeof() return an unsigned value
     */
    if (maxbytes >= (int) sizeof(val))
        memcpy(buf, (void *) &val, sizeof(val));
}

int main() {
    int maxbytes = sizeof(int) * 10;
    void *buf = malloc(maxbytes);
    int val = 0x12345678;

    copy_int(val, buf, maxbytes);
    assert(*(int *) buf == val);

    val = 0xaabbccdd;
    copy_int(val, buf, 0);
    assert(*(int *) buf = val);

    return 0;
}
