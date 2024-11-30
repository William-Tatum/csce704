#include <stdlib.h>

int* returnHeapVariableAddress() {
    int* heapVariable = malloc(sizeof(int));
    if (heapVariable == NULL) {
        exit(1);
    }
    *heapVariable = 42;
    return heapVariable;
}

int main() {
    int* safePointer = returnHeapVariableAddress();
    free(safePointer);
    return 0;
}