#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL_ALLOC 1024 * 1024 // 1 MB limit
#define MAX_OBJECTS 100

typedef struct {
    char *data;
    size_t size;
} Object;

int main() {
    Object *objects[MAX_OBJECTS];
    size_t totalAllocated = 0;
    size_t inputSize;
    int objectCount = 0;

    while (objectCount < MAX_OBJECTS) {
        printf("Enter size for object %d: ", objectCount + 1);
        scanf("%zu", &inputSize);

        if (totalAllocated + inputSize > MAX_TOTAL_ALLOC) {
            printf("Cannot allocate more memory. Total limit reached.\n");
            break;
        }

        objects[objectCount] = (Object *)malloc(sizeof(Object));
        if (!objects[objectCount]) {
            printf("Memory allocation failed.\n");
            break;
        }

        objects[objectCount]->data = (char *)malloc(inputSize);
        if (!objects[objectCount]->data) {
            printf("Memory allocation failed for object data.\n");
            free(objects[objectCount]);
            break;
        }

        objects[objectCount]->size = inputSize;
        totalAllocated += inputSize;
        objectCount++;
    }

    for (int i = 0; i < objectCount; i++) {
        free(objects[i]->data);
        free(objects[i]);
    }

    printf("Program finished. Total allocated memory: %zu bytes\n", totalAllocated);
    return 0;
}