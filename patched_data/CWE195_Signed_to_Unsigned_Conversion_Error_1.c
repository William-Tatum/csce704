#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int riskyFunction() {
    return -1;
}

int main() {
    int result = riskyFunction();
    if (result < 0) {
        printf("Error: function returned a negative value.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int size = (unsigned int)result;
    if (size == 0) {
        printf("Error: size is zero, aborting memory allocation.\n");
        exit(EXIT_FAILURE);
    }

    char *buffer = (char *)malloc(size);
    if (!buffer) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(buffer, "This is a test.", size - 1);
    buffer[size - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
    free(buffer);
    return 0;
}