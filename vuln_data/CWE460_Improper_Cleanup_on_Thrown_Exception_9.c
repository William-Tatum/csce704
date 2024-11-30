#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void cleanup_resources(int *resource) {
    if (resource != NULL) {
        free(resource);
        printf("Resources cleaned up\n");
    }
}

void do_something_risky(int should_throw) {
    int *resource = malloc(sizeof(int));
    if (resource == NULL) {
        longjmp(buf, 1);
    }

    if (should_throw) {
        longjmp(buf, 1);
    }

    *resource = 42;
    printf("Resource value: %d\n", *resource);
    cleanup_resources(resource);
}

int main() {
    if (setjmp(buf)) {
        printf("An error occurred. Exiting without proper cleanup\n");
        return 1;
    }

    do_something_risky(1);

    return 0;
}