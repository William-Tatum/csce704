#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL_MEMORY (1024 * 1024)

int main() {
    int *allocations[1000] = {0};  // Initialize to NULL for safety
    size_t totalMemoryAllocated = 0;
    size_t allocationSize = 1024 * sizeof(int);
    int numAllocations = 0;

    while (numAllocations < 1000) {
        if (totalMemoryAllocated + allocationSize > MAX_TOTAL_MEMORY) {
            printf("Cannot allocate more memory, limit reached.\n");
            break;
        }

        allocations[numAllocations] = (int *)malloc(allocationSize);
        if (allocations[numAllocations] == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }
        totalMemoryAllocated += allocationSize;
        numAllocations++;
    }

    for (int i = 0; i < numAllocations; i++) {
        if (allocations[i] != NULL) {
            free(allocations[i]);
            allocations[i] = NULL;
        }
    }

    return 0;
}