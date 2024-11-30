#include <stdio.h>
#include <string.h>

void secureFunction(const char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
}

int main() {
    char userInput[50];
    printf("Enter input: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    secureFunction(userInput);
    printf("Buffer overflow example completed.\n");
    return 0;
}