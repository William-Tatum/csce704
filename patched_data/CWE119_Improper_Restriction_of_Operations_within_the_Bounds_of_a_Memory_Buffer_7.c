#include <stdio.h>
#include <string.h>

void copyInput(const char* input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char userInput[20];
    printf("Enter input: ");
    if (fgets(userInput, sizeof(userInput), stdin)) {
        userInput[strcspn(userInput, "\n")] = 0;
        copyInput(userInput);
    }
    return 0;
}