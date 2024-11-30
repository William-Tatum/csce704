#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }
    free(ptr);

    /* Vulnerable code: Freeing the pointer again without resetting or re-allocating */
    free(ptr);

    return 0;
}