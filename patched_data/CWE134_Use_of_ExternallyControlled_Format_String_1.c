#include <stdio.h>
#include <string.h>

void safeFunction(const char *userInput) {
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "%s", userInput);
    printf("%s\n", buffer);
}

int main() {
    char userInput[256];
    if (fgets(userInput, sizeof(userInput), stdin)) {
        userInput[strcspn(userInput, "\n")] = '\0';
        safeFunction(userInput);
    }
    return 0;
}