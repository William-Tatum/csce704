#include <stdio.h>
#include <stdlib.h>

int* getHeapVariableAddress() {
    int *heapVariable = malloc(sizeof(int));
    if (heapVariable == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    *heapVariable = 42;
    return heapVariable;
}

int main() {
    int *ptr = getHeapVariableAddress();
    printf("Value at returned address: %d\n", *ptr);
    free(ptr);
    return 0;
}