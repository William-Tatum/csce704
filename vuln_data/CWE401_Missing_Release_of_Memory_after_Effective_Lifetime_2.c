#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(const char *input) {
    char *buffer = (char *)malloc(256);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    strcpy(buffer, input);
    printf("Processing: %s\n", buffer);

    // Simulating an early return, which could occur due to malformed data
    if (strlen(input) > 100) {
        printf("Input too long, skipping processing\n");
        return;
    }

    // Additional processing here

    free(buffer);
}

int main() {
    char data[] = "Example of input data.";
    process_data(data);
    return 0;
}