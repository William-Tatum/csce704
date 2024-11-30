#include <stdio.h>
#include <string.h>

void safeFunction(char *input) {
    char buffer[10];
    if (strnlen(input, sizeof(buffer)) < sizeof(buffer)) {
        strncpy(buffer, input, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';
        printf("Buffer contains: %s\n", buffer);
    } else {
        printf("Input too large for buffer!\n");
    }
}

int main() {
    char userInput[20];
    printf("Enter a string: ");
    if (fgets(userInput, sizeof(userInput), stdin)) {
        userInput[strcspn(userInput, "\n")] = 0;
        safeFunction(userInput);
    }
    return 0;
}