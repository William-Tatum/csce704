#include <stdio.h>
#include <stdlib.h>

int* returnHeapAddress() {
    int* heapVar = (int*)malloc(sizeof(int));
    if (heapVar == NULL) {
        return NULL;
    }
    *heapVar = 42;
    return heapVar;
}

int main() {
    int* ptr = returnHeapAddress();
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
        free(ptr);
    } else {
        printf("Memory allocation failed\n");
    }
    return 0;
}