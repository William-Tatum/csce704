#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }
    *ptr = 42;
    free(ptr);
    *ptr = 50;
    printf("Value: %d\n", *ptr);
    int *newPtr = (int *)malloc(sizeof(int));
    if (newPtr == NULL) {
        return 1;
    }
    *newPtr = 100;
    printf("New Value: %d\n", *newPtr);
    printf("Old Pointer: %d\n", *ptr);
    free(newPtr);
    return 0;
}