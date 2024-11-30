#include <stdio.h>
#include <string.h>

void copyInput(char* input) {
    char buffer[10];
    if (strlen(input) >= 10) {
        printf("Input too large.\n");
        return;
    }
    strcpy(buffer, input);
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char userInput[20];
    printf("Enter input: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    copyInput(userInput);
    return 0;
}