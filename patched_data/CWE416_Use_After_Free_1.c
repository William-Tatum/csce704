#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    *ptr = 42;
    free(ptr);
    ptr = NULL;

    int *newPtr = (int*)malloc(sizeof(int));
    if (newPtr == NULL) {
        return 1;
    }
    
    *newPtr = 13;

    printf("New allocation: %d\n", *newPtr);

    free(newPtr);
    newPtr = NULL;
    return 0;
}