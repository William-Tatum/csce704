#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getValue() {
    return -1; // Simulating an error condition which returns a negative value
}

int main() {
    int signedValue = getValue();
    if (signedValue < 0) {
        fprintf(stderr, "Error: Negative size value\n");
        exit(EXIT_FAILURE);
    }

    unsigned int sizeValue = (unsigned int)signedValue;

    if (sizeValue == 0) {
        fprintf(stderr, "Error: Zero size value\n");
        exit(EXIT_FAILURE);
    }

    char *buffer = (char *)malloc(sizeValue);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeValue);
    free(buffer);

    return 0;
}