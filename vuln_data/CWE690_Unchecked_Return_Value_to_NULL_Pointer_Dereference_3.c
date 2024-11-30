#include <stdio.h>
#include <stdlib.h>

char* allocate_memory(size_t size) {
    if (size == 0) return NULL;
    return (char*)malloc(size);
}

int main() {
    char *data = allocate_memory(1024);
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    /* Use the allocated memory */
    data[0] = 'A';
    printf("Data: %c\n", data[0]);

    free(data);
    return 0;
}