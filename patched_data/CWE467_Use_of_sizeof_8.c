#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(10 * sizeof(int));
    if (ptr == NULL) {
        return 1; 
    }

    printf("Size of allocated memory: %zu\n", 10 * sizeof(int));

    free(ptr);
    return 0;
}