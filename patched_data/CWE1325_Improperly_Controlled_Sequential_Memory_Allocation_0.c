#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL_ALLOCATION 1024 * 1024

int main() {
    int allocation_count = 0;
    size_t object_size;
    char *object;
    size_t total_allocation = 0;

    while (1) {
        printf("Enter size of object to allocate: ");
        if (scanf("%zu", &object_size) != 1 || object_size <= 0) {
            fprintf(stderr, "Invalid input. Exiting.\n");
            break;
        }

        if (total_allocation + object_size > MAX_TOTAL_ALLOCATION) {
            printf("Exceeded maximum total allocation limit.\n");
            break;
        }

        object = (char *)malloc(object_size);
        if (object == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }

        total_allocation += object_size;
        allocation_count++;

        printf("Allocated object %d of size %zu bytes. Total allocation: %zu bytes.\n",
               allocation_count, object_size, total_allocation);

        free(object);
    }

    printf("Total objects allocated: %d\n", allocation_count);
    return 0;
}