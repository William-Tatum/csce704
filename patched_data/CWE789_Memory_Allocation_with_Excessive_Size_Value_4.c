#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    unsigned int size;
    printf("Enter the size of memory to allocate: ");
    if (scanf("%u", &size) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (size > 1024) {
        printf("Requested size is out of acceptable range\n");
        return 1;
    }

    void *buffer = malloc(size);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocated successfully\n");
    free(buffer);
    return 0;
}