#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    size_t size;
    printf("Enter the size of the memory to allocate: ");
    if (scanf("%zu", &size) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (size > 1024 || size > (SIZE_MAX / sizeof(int))) {
        printf("Requested size is too large.\n");
        return 1;
    }
    int *array = (int *)malloc(size * sizeof(int));
    if (!array) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Memory allocated successfully.\n");
    free(array);
    return 0;
}