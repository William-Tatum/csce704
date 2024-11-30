#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processInput(const char *input) {
    int i;
    char *buffer;
    size_t len = strlen(input);

    buffer = (char *)malloc(len + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < len; i++) {
        buffer[i] = input[i];
    }
    buffer[len] = '\0';

    printf("Processed: %s\n", buffer);
    free(buffer);
}

int main() {
    const char *input = "Example input string";
    processInput(input);
    return 0;
}