#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intPtr = (int *)malloc(sizeof(int));
    if (intPtr == NULL) {
        return 1;
    }
    *intPtr = 42;

    float *floatPtr = (float *)intPtr;
    printf("Interpreted as float: %f\n", *floatPtr);

    free(intPtr);
    return 0;
}