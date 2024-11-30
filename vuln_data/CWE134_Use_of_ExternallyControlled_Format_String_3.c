#include <stdio.h>

void printMessage(char *userInput) {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), userInput);
    printf("%s\n", buffer);
}

int main() {
    char userInput[256];
    printf("Enter a message: ");
    fgets(userInput, sizeof(userInput), stdin);
    printMessage(userInput);
    return 0;
}