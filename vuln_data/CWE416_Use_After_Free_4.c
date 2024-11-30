#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    *ptr = 50;
    free(ptr);

    // Use after free vulnerability
    printf("%d\n", *ptr);

    // Subsequent allocation
    int *newPtr = (int *)malloc(sizeof(int));
    if (newPtr == NULL) {
        return 1;
    }
    
    *newPtr = 100;

    // Original pointer still points to freed memory
    printf("%d\n", *ptr);

    free(newPtr);
    return 0;
}