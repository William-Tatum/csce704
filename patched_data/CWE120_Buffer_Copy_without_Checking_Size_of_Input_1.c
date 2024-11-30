#include <stdio.h>
#include <string.h>

void copy_input(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Copied Buffer: %s\n", buffer);
}

int main() {
    char userInput[50];
    printf("Enter input: ");
    scanf("%49s", userInput);
    copy_input(userInput);
    return 0;
}