#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char userInput[20];
    printf("Enter input: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = '\0';
    vulnerableFunction(userInput);
    return 0;
}