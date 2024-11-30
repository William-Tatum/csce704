#include <stdio.h>
#include <stdlib.h>

int main() {
    int *intPtr = malloc(sizeof(int));
    
    if (intPtr == NULL) {
        return -1;
    }

    *intPtr = 12345;

    printf("Integer value: %d\n", *intPtr);

    free(intPtr);
    return 0;
}