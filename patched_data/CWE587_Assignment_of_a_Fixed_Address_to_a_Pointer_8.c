#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    if (ptr != NULL) {
        printf("Pointer is allocated at address: %p\n", (void *)ptr);
        free(ptr);
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}