#include <stdio.h>

const int BUF_SIZE = 12;

void good_echo(void) {
    char buf[BUF_SIZE];
    while(1) {
        char *p = fgets(buf, BUF_SIZE, stdin);
        if (p == NULL)
            break;
        printf("%s", p);
    }
    return;
}

int main(int argc, char *argv[]) {
    good_echo();
    return 0;
}