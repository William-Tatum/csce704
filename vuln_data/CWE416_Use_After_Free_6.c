#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }
    *ptr = 42;
    free(ptr);
    int *newPtr = (int *)malloc(sizeof(int) * 2);
    if (newPtr == NULL) {
        return 1;
    }
    newPtr[0] = 100;
    newPtr[1] = 200;
    printf("%d\n", *ptr); // Use after free
    free(newPtr);
    return 0;
}