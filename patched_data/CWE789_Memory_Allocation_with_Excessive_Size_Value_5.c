#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC_SIZE 1024

void allocateMemory(size_t size) {
    if (size > MAX_ALLOC_SIZE) {
        printf("Requested size is too large.\n");
        return;
    }
    
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Memory allocated successfully.\n");

    free(buffer);
}

int main() {
    size_t requestedSize;
    int result;
    printf("Enter the size of memory to allocate: ");
    
    result = scanf("%zu", &requestedSize);
    if (result != 1) {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }

    allocateMemory(requestedSize);

    return EXIT_SUCCESS;
}