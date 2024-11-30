#include <stdio.h>

void checkPassword(char *input) {
    char *correctPassword = "secure123";
    if (input == correctPassword) {
        printf("Access Granted\n");
    } else {
        printf("Access Denied\n");
    }
}

int main() {
    char userInput[50];
    printf("Enter password: ");
    scanf("%49s", userInput);
    checkPassword(userInput);
    return 0;
}