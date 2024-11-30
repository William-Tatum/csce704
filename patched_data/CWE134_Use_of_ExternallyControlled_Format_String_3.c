#include <stdio.h>

void printMessage(char *userInput) {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%s", userInput);
    printf("%s\n", buffer);
}

int main() {
    char userInput[256];
    printf("Enter a message: ");
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        printMessage(userInput);
    }
    return 0;
}