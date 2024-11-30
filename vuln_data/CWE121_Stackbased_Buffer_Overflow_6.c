#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char buffer[10];
    strcpy(buffer, input); // Unsafe copying to buffer without size check
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char userInput[100];
    printf("Enter data: ");
    fgets(userInput, 100, stdin);
    userInput[strcspn(userInput, "\n")] = '\0';
    vulnerableFunction(userInput);
    return 0;
}