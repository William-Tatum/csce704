#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intPtr = malloc(sizeof(int));
    if (!intPtr) return 1;
    *intPtr = 12345;
    printf("Accessing integer: %d\n", *intPtr);
    free(intPtr);
    return 0;
}