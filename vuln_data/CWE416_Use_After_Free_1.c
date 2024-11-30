#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    *ptr = 42;
    free(ptr);

    int *newPtr = (int*)malloc(sizeof(int));
    if (newPtr == NULL) {
        return 1;
    }
    
    *newPtr = 13;

    printf("Use after free: %d\n", *ptr);

    free(newPtr);
    return 0;
}