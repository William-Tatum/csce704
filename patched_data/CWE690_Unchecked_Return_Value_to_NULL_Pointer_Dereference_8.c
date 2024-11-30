#include <stdio.h>
#include <stdlib.h>

int* allocateMemory(size_t size) {
    if (size == 0 || size > SIZE_MAX / sizeof(int)) {
        return NULL;
    }
    return (int*)malloc(size * sizeof(int));
}

int main() {
    int *data = allocateMemory(10);
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    data[0] = 42;
    printf("%d\n", data[0]);
    
    free(data);
    return 0;
}