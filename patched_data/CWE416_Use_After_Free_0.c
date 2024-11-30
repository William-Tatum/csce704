#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    
    free(ptr);
    ptr = NULL; // Avoid dangling pointer

    int *newPtr = (int *)malloc(sizeof(int));
    if (newPtr == NULL) {
        return 1;
    }
    *newPtr = 100;
    printf("New Value: %d\n", *newPtr);

    if (ptr != NULL) {
        printf("Old Pointer: %d\n", *ptr);
    } else {
        printf("Old Pointer: NULL\n");
    }

    free(newPtr);
    newPtr = NULL; // Avoid dangling pointer
    return 0;
}