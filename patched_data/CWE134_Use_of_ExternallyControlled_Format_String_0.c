#include <stdio.h>
#include <string.h>

void printMessage(const char *userInput) {
    char fmtBuffer[256];
    if (snprintf(fmtBuffer, sizeof(fmtBuffer), "%s", userInput) < 0) {
        printf("Formatting error\n");
        return;
    }
    printf("%s\n", fmtBuffer);
}

int main() {
    char userControlledInput[256];
    printf("Enter your message: ");
    if (fgets(userControlledInput, sizeof(userControlledInput), stdin) != NULL) {
        userControlledInput[strcspn(userControlledInput, "\n")] = 0;
        printMessage(userControlledInput);
    } else {
        printf("Input error\n");
    }
    return 0;
}