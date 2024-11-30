#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_MEMORY_SIZE 1024

int main() {
    size_t untrusted_size;
    printf("Enter the size of memory to allocate: ");
    if (scanf("%zu", &untrusted_size) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (untrusted_size > MAX_MEMORY_SIZE || untrusted_size == 0) {
        fprintf(stderr, "Requested memory size is invalid\n");
        return 1;
    }

    char *buffer = (char *)malloc(untrusted_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocation successful\n");
    free(buffer);
    return 0;
}