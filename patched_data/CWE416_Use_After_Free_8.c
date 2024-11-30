#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 4);
    if (!ptr) return 1;

    for (int i = 0; i < 4; i++) {
        ptr[i] = i + 1;
    }

    free(ptr);
    ptr = NULL; // Prevent use-after-free

    int *newPtr = (int *)malloc(sizeof(int) * 4);
    if (!newPtr) return 1;

    for (int i = 0; i < 4; i++) {
        newPtr[i] = (i + 1) * 10;
    }

    printf("Valid pointer usage: %d\n", newPtr[0]);

    free(newPtr);

    return 0;
}