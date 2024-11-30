#include <stdio.h>
#include <stdlib.h>

int* getHeapVariableAddress() {
    int* heapVariable = malloc(sizeof(int));
    if (heapVariable != NULL) {
        *heapVariable = 42;
    }
    return heapVariable;
}

int main() {
    int* ptr = getHeapVariableAddress();
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
        free(ptr);
    }
    return 0;
}