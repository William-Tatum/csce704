#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int riskyFunction() {
    // Simulate a failure
    return -1;
}

int main() {
    int result = riskyFunction();
    if (result < 0) {
        printf("Error: function returned a negative value.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int size = (unsigned int)result;
    char *buffer = (char *)malloc(size);
    if (!buffer) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(buffer, "This is a test.");
    printf("Buffer content: %s\n", buffer);
    free(buffer);
    return 0;
}