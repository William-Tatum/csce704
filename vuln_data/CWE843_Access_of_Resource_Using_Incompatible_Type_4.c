#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intPtr = malloc(sizeof(int));
    if (!intPtr) {
        return 1;
    }

    *intPtr = 42;

    char *charPtr = (char*)intPtr;

    printf("Incompatible access: %c\n", *charPtr);

    free(intPtr);
    return 0;
}