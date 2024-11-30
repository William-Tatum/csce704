#include <stdio.h>
#include <string.h>

void copy_input(char *input) {
    char buffer[10];
    strcpy(buffer, input); // Potential buffer overflow if input is larger than 10 characters
    printf("Copied Buffer: %s\n", buffer);
}

int main() {
    char userInput[50];
    printf("Enter input: ");
    scanf("%49s", userInput);
    copy_input(userInput);
    return 0;
}