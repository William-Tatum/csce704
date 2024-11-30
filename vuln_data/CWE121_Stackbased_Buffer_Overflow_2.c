#include <stdio.h>
#include <string.h>

void vulnerableFunction(const char *input) {
    char buffer[10];
    strcpy(buffer, input);
}

int main() {
    char userInput[50];
    printf("Enter input: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    vulnerableFunction(userInput);
    printf("Buffer overflow example completed.\n");
    return 0;
}