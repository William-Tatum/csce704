#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TOTAL_ALLOCATION 1024 * 1024

int main() {
    int num_objects;
    size_t object_size;
    size_t total_allocated = 0;

    printf("Enter number of objects: ");
    if (scanf("%d", &num_objects) != 1 || num_objects <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter size of each object: ");
    if (scanf("%zu", &object_size) != 1 || object_size <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (num_objects > INT_MAX || object_size > SIZE_MAX) {
        printf("Input exceeds allowable limits.\n");
        return 1;
    }

    if (object_size > MAX_TOTAL_ALLOCATION / num_objects) {
        printf("Requested size too large for specified number of objects.\n");
        return 1;
    }

    for (int i = 0; i < num_objects; i++) {
        if (total_allocated + object_size > MAX_TOTAL_ALLOCATION) {
            printf("Memory limit exceeded.\n");
            return 1;
        }
        void *ptr = malloc(object_size);
        if (ptr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        total_allocated += object_size;
        free(ptr);  // Ensure allocated memory is freed
    }

    printf("Memory allocation successful, total allocated: %zu bytes.\n", total_allocated);
    return 0;
}