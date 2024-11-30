#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256

void processData(const char *data, unsigned int length) {
    char buffer[MAX_LENGTH];
    if (length > MAX_LENGTH - 1) {
        fprintf(stderr, "Error: Input length exceeds buffer capacity.\n");
        return;
    }
    strncpy(buffer, data, length);
    buffer[length] = '\0';
    printf("Processed data: %s\n", buffer);
}

int main() {
    char input[MAX_LENGTH];
    unsigned int declaredLength;

    printf("Enter the data: ");
    if (!fgets(input, sizeof(input), stdin)) {
        fprintf(stderr, "Failed to read input.\n");
        return 1;
    }
    char *newline = strchr(input, '\n');
    if (newline) *newline = '\0';

    printf("Enter the declared length: ");
    if (scanf("%u", &declaredLength) != 1) {
        fprintf(stderr, "Invalid input for length.\n");
        return 1;
    }

    unsigned int actualLength = strlen(input);
    if (declaredLength != actualLength) {
        fprintf(stderr, "Error: Declared length does not match actual input length.\n");
        return 1;
    }

    processData(input, declaredLength);
    return 0;
}