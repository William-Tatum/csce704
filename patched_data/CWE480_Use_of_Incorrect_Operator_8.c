#include <stdio.h>
#include <string.h>

void checkPassword(char *input) {
    char *correctPassword = "secure123";
    if (strcmp(input, correctPassword) == 0) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
}

int main() {
    char userInput[50];
    printf("Enter password: ");
    if (scanf("%49s", userInput) == 1) {
        checkPassword(userInput);
    } else {
        printf("Error reading input\n");
    }
    return 0;
}