# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# include <string.h>

/* function that allocates memory
 * for an arrary of nmemb elements of
 * size bytes each.
 * either the nmemb or size is zero
 * will return NULL
 */
void *calloc(size_t nmemb, size_t size) {
    if (!nmemb || !size)
        return NULL;
    size_t buf_size = nmemb * size;
    if (size == buf_size / nmemb) {
        size_t *mptr = malloc(nmemb * size);
        if (mptr) {
             memset(mptr, 0, buf_size);
             return mptr;
        }
    }
    return NULL;
}

int main() {
    void *p;
    p = calloc(0x1234, 2);
    assert(p);
    free(p);

    p = calloc(SIZE_MAX, 2);
    assert(!p);
    free(p);

    return 0;
}
