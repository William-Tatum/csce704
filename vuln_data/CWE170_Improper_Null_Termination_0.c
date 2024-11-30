#include <stdio.h>
#include <string.h>

void vulnerableFunction(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer));
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char userInput[15];
    printf("Enter input: ");
    scanf("%14s", userInput);
    vulnerableFunction(userInput);
    return 0;
}