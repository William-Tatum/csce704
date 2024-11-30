#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL_MEMORY 1024 * 1024  // Limit to 1MB

int main() {
    int *allocations[1000];
    int totalMemoryAllocated = 0;
    int allocationSize = 1024;
    int numAllocations = 0;

    while (numAllocations < 1000) {
        if (totalMemoryAllocated + allocationSize > MAX_TOTAL_MEMORY) {
            printf("Cannot allocate more memory, limit reached.\n");
            break;
        }

        allocations[numAllocations] = (int *)malloc(allocationSize * sizeof(int));
        if (allocations[numAllocations] == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }
        totalMemoryAllocated += allocationSize * sizeof(int);
        numAllocations++;
    }

    for (int i = 0; i < numAllocations; i++) {
        free(allocations[i]);
    }

    return 0;
}