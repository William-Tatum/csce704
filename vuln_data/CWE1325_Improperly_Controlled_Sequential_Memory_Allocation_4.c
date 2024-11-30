#include <stdio.h>
#include <stdlib.h>

#define MAX_TOTAL_ALLOCATION 1024 * 1024
#define OBJECT_SIZE 256

int main() {
    void *objects[1024];
    int numObjects = 0;
    size_t totalAllocated = 0;
    
    while (1) {
        if (totalAllocated + OBJECT_SIZE > MAX_TOTAL_ALLOCATION) {
            printf("Memory limit reached. Cannot allocate more objects.\n");
            break;
        }
        
        objects[numObjects] = malloc(OBJECT_SIZE);
        if (objects[numObjects] == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }
        
        totalAllocated += OBJECT_SIZE;
        numObjects++;
    }
    
    for (int i = 0; i < numObjects; i++) {
        free(objects[i]);
    }

    return 0;
}