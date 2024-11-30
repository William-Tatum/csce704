#include <stdio.h>
#include <stdlib.h>

int* getValue() {
    int* heapVar = (int*)malloc(sizeof(int));
    if (!heapVar) {
        return NULL; // Handle memory allocation failure
    }
    *heapVar = 42;
    return heapVar;
}

int main() {
    int* ptr = getValue();
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
        free(ptr); // Free allocated memory
    }
    return 0;
}