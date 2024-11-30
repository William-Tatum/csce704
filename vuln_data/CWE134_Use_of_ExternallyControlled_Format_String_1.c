#include <stdio.h>
#include <string.h>

void unsafeFunction(char *userInput) {
    char buffer[128];
    snprintf(buffer, sizeof(buffer), userInput);
    printf("%s\n", buffer);
}

int main() {
    char userInput[256];
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = '\0';
    unsafeFunction(userInput);
    return 0;
}