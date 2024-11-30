#include <stdio.h>
#include <stdlib.h>

int* returnHeapVariableAddress() {
    int* x = (int*)malloc(sizeof(int));
    if (x) {
        *x = 42;
    }
    return x;
}

int main() {
    int* safePointer = returnHeapVariableAddress();
    if (safePointer) {
        printf("Value: %d\n", *safePointer);
        free(safePointer);
    }
    return 0;
}