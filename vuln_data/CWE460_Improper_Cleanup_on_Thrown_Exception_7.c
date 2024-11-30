#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void cleanup() {
    printf("Cleanup performed\n");
}

void problematicFunction() {
    if (setjmp(buf)) {
        // Simulate exception handling
        printf("Exception caught\n");
        return;
    }

    char *buffer = (char *)malloc(100 * sizeof(char));
    // Simulated operation that could fail
    if (buffer == NULL) {
        longjmp(buf, 1);
    }

    // Simulate an exception condition being met
    if (1) {
        longjmp(buf, 1);
    }

    // Normally, cleanup would be here
    free(buffer);
}

int main() {
    cleanup();
    problematicFunction();
    return 0;
}