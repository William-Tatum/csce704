#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void processData(char *input, size_t length) {
    if (length == 0 || length > strlen(input) + 1) {
        printf("Error: Invalid length parameter\n");
        return;
    }

    char *buffer = (char *)malloc(length);
    if (!buffer) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    strncpy(buffer, input, length - 1);
    buffer[length - 1] = '\0';

    printf("Processed data: %s\n", buffer);
    free(buffer);
}

int main() {
    char input[100];
    size_t length;

    printf("Enter data: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error: Failed to read input\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    printf("Enter length: ");
    if (scanf("%zu", &length) != 1) {
        printf("Error: Invalid input\n");
        return 1;
    }

    processData(input, length);
    return 0;
}