#include <stdio.h>
#include <string.h>

void processInput(const char *input) {
    char buffer[100];
    size_t length = strnlen(input, sizeof(buffer) - 1);

    if (length == sizeof(buffer) - 1 && input[length] != '\0') {
        printf("Input too long!\n");
        return;
    }

    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    printf("Processed input: %s\n", buffer);
}

int main() {
    char userInput[150];
    printf("Enter a string: ");
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        userInput[strcspn(userInput, "\n")] = '\0';
        processInput(userInput);
    }
    return 0;
}