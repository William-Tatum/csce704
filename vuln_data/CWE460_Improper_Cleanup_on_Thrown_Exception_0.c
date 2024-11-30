#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void faultyFunction() {
    int *resource = malloc(sizeof(int));
    if (setjmp(env)) {
        // Improper cleanup; resource not freed
        printf("Exception caught - improper cleanup\n");
        return;
    }
    // Some processing with 'resource'
    if (/* some condition that leads to an exception */) {
        longjmp(env, 1);
    }
    printf("Function executed successfully\n");
    free(resource); // Correct cleanup if no exception occurs
}

int main() {
    faultyFunction();
    return 0;
}