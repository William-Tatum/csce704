#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void processMessage(char *input, int length) {
    if (length > MAX_BUFFER_SIZE || length < 0) {
        printf("Error: Invalid length.\n");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    if (length < strlen(input)) {
        printf("Error: Inconsistent length parameter.\n");
        return;
    }

    strncpy(buffer, input, length);
    buffer[length] = '\0';

    printf("Processed message: %s\n", buffer);
}

int main() {
    char *userInput = "SafeInput";
    int userLength = 9;

    processMessage(userInput, userLength);
    return 0;
}