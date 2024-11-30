#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void printMessage(char *userInput) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "User input: %s", userInput);
    printf("%s\n", buffer);
}

int main() {
    char userInput[BUFFER_SIZE];
    printf("Enter a message: ");
    if (fgets(userInput, BUFFER_SIZE, stdin) != NULL) {
        userInput[strcspn(userInput, "\n")] = '\0'; // Remove newline character
        printMessage(userInput);
    }
    return 0;
}