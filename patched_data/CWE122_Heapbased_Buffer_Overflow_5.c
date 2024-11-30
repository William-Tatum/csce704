#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safeFunction(const char *input) {
    size_t inputLength = strlen(input);
    char *buffer = (char *)malloc(inputLength + 1);
    if (!buffer) {
        printf("Memory allocation failed\n");
        return;
    }
    strncpy(buffer, input, inputLength);
    buffer[inputLength] = '\0';
    printf("Buffer contents: %s\n", buffer);
    free(buffer);
}

int main() {
    char largeInput[20];
    strncpy(largeInput, "This is a long input", sizeof(largeInput) - 1);
    largeInput[sizeof(largeInput) - 1] = '\0';
    safeFunction(largeInput);
    return 0;
}