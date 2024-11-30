#include <stdlib.h>
#include <stdio.h>

int main() {
    int *data = (int*)malloc(sizeof(int));
    if (data == NULL) return 1;
    
    *data = 42;
    printf("Data: %d\n", *data);
    free(data);
    data = NULL;

    int *new_data = (int*)malloc(sizeof(int));
    if (new_data == NULL) return 1;
    *new_data = 24;
    printf("Data: %d\n", *new_data);

    free(new_data);
    new_data = NULL;

    return 0;
}