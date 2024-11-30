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
    if (snprintf(data, 1024, "Memory allocated successfully") >= 1024) {
        fprintf(stderr, "Data truncation occurred\n");
        free(data);
        return 1;
    }
    printf("%s\n", data);
    free(data);
    return 0;
}