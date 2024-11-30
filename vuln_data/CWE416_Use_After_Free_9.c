#include <stdlib.h>
#include <stdio.h>

int main() {
    int *data = (int*)malloc(sizeof(int));
    if (data == NULL) return 1;
    
    *data = 42;
    free(data);

    // Use after free vulnerability
    printf("Data: %d\n", *data);

    int *new_data = (int*)malloc(sizeof(int));
    if (new_data == NULL) return 1;
    *new_data = 24;

    // The old pointer is now incorrectly reused
    printf("Data: %d\n", *data);

    free(new_data);

    return 0;
}