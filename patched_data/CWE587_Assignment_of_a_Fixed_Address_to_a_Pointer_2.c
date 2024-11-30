#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pointer = NULL;

    if ((pointer = (int *)malloc(sizeof(int))) == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    printf("Pointer address: %p\n", (void *)pointer);

    free(pointer);
    return EXIT_SUCCESS;
}