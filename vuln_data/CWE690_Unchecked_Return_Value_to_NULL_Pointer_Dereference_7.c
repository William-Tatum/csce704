#include <stdio.h>
#include <stdlib.h>

char* allocate_memory(size_t size) {
    return malloc(size);
}

int main() {
    char *data = allocate_memory(1024);
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    // Use the allocated memory
    snprintf(data, 1024, "Memory allocated successfully");
    printf("%s\n", data);
    free(data);
    return 0;
}