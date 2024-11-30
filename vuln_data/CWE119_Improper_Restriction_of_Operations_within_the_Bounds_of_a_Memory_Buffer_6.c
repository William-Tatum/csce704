#include <stdio.h>
#include <string.h>

void safeFunction(char *input) {
    char buffer[10];
    if (strlen(input) < sizeof(buffer)) {
        strcpy(buffer, input);
        printf("Buffer contains: %s\n", buffer);
    } else {
        printf("Input too large for buffer!\n");
    }
}

int main() {
    char userInput[20];
    printf("Enter a string: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    safeFunction(userInput);
    return 0;
}