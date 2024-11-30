#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_ALLOC_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    char *endptr;
    errno = 0;
    unsigned long size = strtoul(argv[1], &endptr, 10);

    if (errno != 0 || *endptr != '\0' || endptr == argv[1]) {
        printf("Invalid input for size.\n");
        return 1;
    }

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