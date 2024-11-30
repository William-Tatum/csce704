#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_data_size() {
    return -10;
}

int main() {
    int size = get_data_size();

    if (size <= 0) {
        fprintf(stderr, "Error: Invalid size value\n");
        return EXIT_FAILURE;
    }

    unsigned int unsigned_size = (unsigned int)size;

    char *buffer = malloc(unsigned_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    strncpy(buffer, "Safe use of buffer", unsigned_size - 1);
    buffer[unsigned_size - 1] = '\0';

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}