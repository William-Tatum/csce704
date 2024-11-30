#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL_MEMORY 10240

typedef struct {
    int data;
} Object;

int main() {
    int totalMemoryAllocated = 0;
    Object **objects = malloc(100 * sizeof(Object *));
    if (!objects) {
        perror("Memory allocation for object pointers failed");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        if (totalMemoryAllocated + sizeof(Object) > MAX_TOTAL_MEMORY) {
            printf("Memory limit reached. Cannot allocate more objects.\n");
            break;
        }
        objects[i] = malloc(sizeof(Object));
        if (!objects[i]) {
            perror("Memory allocation for object failed");
            break;
        }
        totalMemoryAllocated += sizeof(Object);
    }

    for (int i = 0; i < 100; i++) {
        if (objects[i]) free(objects[i]);
    }
    free(objects);
    return 0;
}