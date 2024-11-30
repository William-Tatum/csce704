#include <stdio.h>
#include <stdlib.h>

int* safeFunction() {
    int* localVariable = malloc(sizeof(int));
    if (localVariable == NULL) {
        return NULL;
    }
    *localVariable = 42;
    return localVariable;
}

int main() {
    int* ptr = safeFunction();
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Dereferenced value: %d\n", *ptr);
    free(ptr);
    return 0;
}