#include <stdio.h>
#include <stdlib.h>

int* allocateMemory(size_t size) {
    return (int*)malloc(size * sizeof(int));
}

int main() {
    int *data = allocateMemory(10);
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    // Example usage of data
    data[0] = 42;
    printf("%d\n", data[0]);
    
    free(data);
    return 0;
}