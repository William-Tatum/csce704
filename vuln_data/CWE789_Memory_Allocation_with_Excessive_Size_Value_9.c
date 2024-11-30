#define MAX_ALLOC_SIZE 1024

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t input_size;
    printf("Enter the size of memory to allocate: ");
    if(scanf("%zu", &input_size) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if(input_size > MAX_ALLOC_SIZE) {
        printf("Requested size is too large\n");
        return 1;
    }
    void* memory = malloc(input_size);
    if(memory == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Memory allocated successfully\n");
    free(memory);
    return 0;
}