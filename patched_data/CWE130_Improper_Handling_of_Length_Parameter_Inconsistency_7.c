#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void processMessage(const char *input, size_t length) {
    if (length > MAX_BUFFER_SIZE || length < 0) {
        printf("Error: Invalid length.\n");
        return;
    }

    if (length > strlen(input)) {
        length = strlen(input);
    }

    char buffer[MAX_BUFFER_SIZE];
    strncpy(buffer, input, length);
    buffer[length] = '\0';

    printf("Processed message: %s\n", buffer);
}

int main() {
    const char *userInput = "SafeInput";
    size_t userLength = 9;

    processMessage(userInput, userLength);
    return 0;
}