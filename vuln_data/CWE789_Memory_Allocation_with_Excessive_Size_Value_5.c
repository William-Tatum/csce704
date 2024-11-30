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
        exit(1);
    }

    printf("Memory allocated successfully.\n");

    free(buffer);
}

int main() {
    size_t requestedSize;
    printf("Enter the size of memory to allocate: ");
    scanf("%zu", &requestedSize);

    allocateMemory(requestedSize);

    return 0;
}