#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intPtr = (int *)malloc(sizeof(int));
    if (intPtr == NULL) {
        return 1;
    }
    *intPtr = 42;

    printf("Interpreted as integer: %d\n", *intPtr);

    free(intPtr);
    return 0;
}