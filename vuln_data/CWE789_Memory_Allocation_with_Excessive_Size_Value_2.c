#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size;
    printf("Enter the number of bytes to allocate: ");
    if (scanf("%zu", &size) != 1 || size > 1024) {
        printf("Invalid input or size too large!\n");
        return 1;
    }
    char *buffer = malloc(size);
    if (!buffer) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Memory allocated successfully.\n");
    free(buffer);
    return 0;
}