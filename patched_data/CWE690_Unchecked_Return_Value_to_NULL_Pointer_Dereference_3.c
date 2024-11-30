#include <stdio.h>
#include <stdlib.h>

char* allocate_memory(size_t size) {
    if (size == 0) return NULL;
    char *ptr = (char*)malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main() {
    char *data = allocate_memory(1024);

    data[0] = 'A';
    printf("Data: %c\n", data[0]);

    free(data);
    return 0;
}