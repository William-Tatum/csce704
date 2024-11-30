#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TOTAL_ALLOCATION 10240
#define OBJECT_SIZE 256

int main() {
    int num_objects;
    printf("Enter the number of objects to allocate: ");
    if (scanf("%d", &num_objects) != 1 || num_objects < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (num_objects > MAX_TOTAL_ALLOCATION / OBJECT_SIZE) {
        printf("Memory allocation request exceeds the limit.\n");
        return 1;
    }

    char **objects = (char **)malloc(num_objects * sizeof(char *));
    if (!objects) {
        printf("Failed to allocate memory for object pointers.\n");
        return 1;
    }

    for (int i = 0; i < num_objects; i++) {
        objects[i] = (char *)malloc(OBJECT_SIZE);
        if (!objects[i]) {
            printf("Failed to allocate memory for object %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(objects[j]);
            }
            free(objects);
            return 1;
        }
    }

    for (int i = 0; i < num_objects; i++) {
        free(objects[i]);
    }
    free(objects);

    printf("Memory allocated and deallocated successfully.\n");
    return 0;
}