#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(const char *input) {
    char *buffer = (char *)malloc(256);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    if (strlen(input) >= 256) {
        fprintf(stderr, "Input is too large\n");
        free(buffer);
        return;
    }

    strcpy(buffer, input);
    printf("Processing: %s\n", buffer);

    if (strlen(input) > 100) {
        printf("Input too long, skipping processing\n");
        free(buffer);
        return;
    }

    free(buffer);
}

int main() {
    char data[] = "Example of input data.";
    process_data(data);
    return 0;
}