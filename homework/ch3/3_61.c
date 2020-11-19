#include <stdio.h>

long cred(long *xp) {
    return (!xp ? 0 : *xp);
}
