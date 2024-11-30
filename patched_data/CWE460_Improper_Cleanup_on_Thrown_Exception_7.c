#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void cleanup() {
    printf("Cleanup performed\n");
}

void problematicFunction() {
    char *buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    if (setjmp(buf)) {
        printf("Exception caught\n");
        free(buffer);
        return;
    }

    if (1) { // Simulate exception condition
        longjmp(buf, 1);
    }

    free(buffer);
}

int main() {
    problematicFunction();
    cleanup();
    return 0;
}