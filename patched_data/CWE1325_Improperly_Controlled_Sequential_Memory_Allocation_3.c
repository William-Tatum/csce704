#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL_MEMORY 1024 * 1024 // 1 MB

int main() {
    size_t totalAllocated = 0;
    size_t objectSize = 10000;
    void *objects[100];
    int i = 0;

    while (i < 100) {
        if ((MAX_TOTAL_MEMORY - totalAllocated) < objectSize) {
            printf("Memory limit reached. Cannot allocate more objects.\n");
            break;
        }

        objects[i] = malloc(objectSize);
        if (objects[i] == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }
        totalAllocated += objectSize;
        i++;
    }

    for (int j = 0; j < i; j++) {
        free(objects[j]);
        objects[j] = NULL;
    }

    printf("Total allocated objects: %d\n", i);
    return 0;
}