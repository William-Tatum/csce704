#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *intPtr = malloc(sizeof(int));
    char *charPtr;

    if (intPtr == NULL) {
        return -1;
    }

    *intPtr = 12345;

    charPtr = (char *)intPtr;

    printf("Integer value: %d\n", *intPtr);
    printf("Char value: %s\n", charPtr);

    free(intPtr);
    return 0;
}