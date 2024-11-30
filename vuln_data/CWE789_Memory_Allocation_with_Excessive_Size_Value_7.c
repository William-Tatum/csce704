#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC_SIZE 1024

void allocateMemory(size_t size) {
    if (size > MAX_ALLOC_SIZE) {
        printf("Requested size is too large\n");
        return;
    }
    void *memory = malloc(size);
    if (memory == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Memory allocated successfully\n");
    free(memory);
}

int main() {
    size_t inputSize;
    printf("Enter the size of memory to allocate: ");
    if (scanf("%zu", &inputSize) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    allocateMemory(inputSize);
    return 0;
}