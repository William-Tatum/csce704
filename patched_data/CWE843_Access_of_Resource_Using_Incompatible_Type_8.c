#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intPointer;
    float *floatPointer;

    intPointer = malloc(sizeof(int));

    if (intPointer == NULL) {
        return 1;
    }

    *intPointer = 10;

    floatPointer = malloc(sizeof(float));

    if (floatPointer == NULL) {
        free(intPointer);
        return 1;
    }

    *floatPointer = (float)*intPointer;

    printf("Interpreted as float: %f\n", *floatPointer);

    free(intPointer);
    free(floatPointer);

    return 0;
}