#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void foo() {
    char *tempResource = (char *)malloc(100);
    if (tempResource == NULL) {
        longjmp(buf, 1);
    }
    if (rand() % 2) {
        free(tempResource);
        longjmp(buf, 1);
    }
    free(tempResource);
}

int main() {
    if (setjmp(buf)) {
        printf("Exception caught!\n");
    } else {
        foo();
    }
    return 0;
}