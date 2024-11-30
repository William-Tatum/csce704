#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    unsigned long size = strtoul(argv[1], NULL, 10);

    if (size > MAX_ALLOC_SIZE) {
        printf("Requested size is too large. Maximum allowed is %d bytes.\n", MAX_ALLOC_SIZE);
        return 1;
    }

    char *buffer = (char *)malloc(size);
    if (!buffer) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Memory allocated successfully.\n");
    free(buffer);
    return 0;
}