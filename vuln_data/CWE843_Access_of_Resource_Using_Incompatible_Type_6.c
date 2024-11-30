#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intPtr = malloc(sizeof(int));
    if (!intPtr) return 1;
    *intPtr = 12345;
    double *dblPtr = (double *)intPtr;
    printf("Accessing integer as double: %f\n", *dblPtr);
    free(intPtr);
    return 0;
}