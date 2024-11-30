#include <stdio.h>
#include <string.h>

void printMessage(char *userInput) {
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
    fgets(userControlledInput, sizeof(userControlledInput), stdin);
    userControlledInput[strcspn(userControlledInput, "\n")] = 0;
    printMessage(userControlledInput);
    return 0;
}