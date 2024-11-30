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

    floatPointer = (float *)intPointer;

    printf("Interpreted as float: %f\n", *floatPointer);

    free(intPointer);

    return 0;
}