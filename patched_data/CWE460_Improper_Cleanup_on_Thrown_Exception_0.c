#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void faultyFunction() {
    int *resource = malloc(sizeof(int));
    if (!resource) {
        perror("Failed to allocate memory");
        return;
    }

    volatile int cleanup_needed = 1;

    if (setjmp(env)) {
        if (cleanup_needed) {
            free(resource);
        }
        printf("Exception caught - proper cleanup\n");
        return;
    }
  
    // Some processing with 'resource'
    if (/* some condition that leads to an exception */) {
        longjmp(env, 1);
    }
  
    printf("Function executed successfully\n");
    cleanup_needed = 0; // No exception, proper cleanup will follow
    free(resource);
}

int main() {
    faultyFunction();
    return 0;
}