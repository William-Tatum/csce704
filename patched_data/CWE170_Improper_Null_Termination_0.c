#include <stdio.h>
#include <string.h>

void secureFunction(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char userInput[15];
    printf("Enter input: ");
    if (scanf("%14s", userInput) == 1) {
        secureFunction(userInput);
    }
    return 0;
}