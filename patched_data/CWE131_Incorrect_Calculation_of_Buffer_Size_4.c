#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safeFunction(const char *input) {
    size_t len = strlen(input);
    char *buffer = (char *)malloc((len + 1) * sizeof(char));
    if (buffer != NULL) {
        strncpy(buffer, input, len);
        buffer[len] = '\0';
        printf("Buffer: %s\n", buffer);
        free(buffer);
    } else {
        fprintf(stderr, "Memory allocation failed\n");
    }
}

int main() {
    char userInput[50];
    printf("Enter input: ");
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        userInput[strcspn(userInput, "\n")] = 0;
        safeFunction(userInput);
    } else {
        fprintf(stderr, "Input error\n");
    }
    return 0;
}