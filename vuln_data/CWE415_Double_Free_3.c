#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1; // Handle memory allocation failure
    }

    *ptr = 42;
    printf("%d\n", *ptr);

    free(ptr);

    // Fix: Set pointer to NULL after freeing to avoid double free
    ptr = NULL;

    // Potential double free, now avoided with the above fix
    if (ptr != NULL) {
        free(ptr);
    }

    return 0;
}