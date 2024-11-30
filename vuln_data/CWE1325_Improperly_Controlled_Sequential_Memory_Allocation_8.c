#include <stdio.h>
#include <stdlib.h>

#define MAX_OBJECTS 100
#define MAX_TOTAL_MEMORY 1024 * 1024

typedef struct {
    char *data;
    size_t size;
} Object;

int main() {
    Object *objects[MAX_OBJECTS];
    size_t current_memory_usage = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        size_t object_size = (rand() % 1024) + 1;
        if (current_memory_usage + object_size > MAX_TOTAL_MEMORY) {
            printf("Memory limit exceeded. Cannot allocate more objects.\n");
            break;
        }
        objects[i] = malloc(sizeof(Object));
        if (objects[i] == NULL) {
            printf("Failed to allocate object structure.\n");
            return 1;
        }
        objects[i]->data = malloc(object_size);
        if (objects[i]->data == NULL) {
            printf("Failed to allocate object data.\n");
            free(objects[i]);
            return 1;
        }
        objects[i]->size = object_size;
        current_memory_usage += object_size;
    }
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (objects[i] != NULL) {
            free(objects[i]->data);
            free(objects[i]);
        }
    }
    return 0;
}