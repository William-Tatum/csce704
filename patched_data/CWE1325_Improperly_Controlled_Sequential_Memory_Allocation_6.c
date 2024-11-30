#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECTS 10
#define MAX_TOTAL_MEMORY 1024

typedef struct {
    char *data;
    size_t size;
} Object;

int main() {
    Object *objects[MAX_OBJECTS] = {NULL};
    size_t total_memory = 0;
    int object_count = 0;

    for (int i = 0; i < MAX_OBJECTS; i++) {
        size_t size;
        printf("Enter size for object %d: ", i);
        if (scanf("%zu", &size) != 1) {
            printf("Invalid input!\n");
            break;
        }
        
        if (object_count >= MAX_OBJECTS || total_memory + size > MAX_TOTAL_MEMORY) {
            printf("Memory limit exceeded or max objects reached!\n");
            break;
        }

        objects[i] = (Object *)malloc(sizeof(Object));
        if (!objects[i]) {
            printf("Memory allocation failed!\n");
            break;
        }

        objects[i]->data = (char *)malloc(size);
        objects[i]->size = size;

        if (objects[i]->data == NULL) {
            printf("Failed to allocate memory for object data\n");
            free(objects[i]);
            objects[i] = NULL;
            break;
        }

        memset(objects[i]->data, 0, size);
        total_memory += size;
        object_count++;
    }

    for (int i = 0; i < object_count; i++) {
        if (objects[i]) {
            free(objects[i]->data);
            free(objects[i]);
        }
    }

    return 0;
}