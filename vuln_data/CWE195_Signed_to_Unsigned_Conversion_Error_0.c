#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_data_size() {
    // Simulating a function that may return a negative value on failure
    return -10;
}

int main() {
    int size = get_data_size();

    // Check for a negative value before casting
    if (size < 0) {
        fprintf(stderr, "Error: Received negative size value\n");
        return EXIT_FAILURE;
    }

    // Safe to cast as size is non-negative
    unsigned int unsigned_size = (unsigned int)size;

    char *buffer = malloc(unsigned_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Perform operations using the safe buffer
    strcpy(buffer, "Safe use of buffer");

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}