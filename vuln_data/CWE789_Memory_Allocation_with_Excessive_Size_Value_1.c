#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main() {
    size_t size;
    printf("Enter the size of memory to allocate: ");
    if (scanf("%zu", &size) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (size > MAX_SIZE) {
        printf("Requested size exceeds the maximum allowed limit\n");
        return 1;
    }

    void *memory = malloc(size);
    if (memory == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocated successfully\n");
    free(memory);
    return 0;
}