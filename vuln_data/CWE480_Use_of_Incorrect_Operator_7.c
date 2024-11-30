#include <stdio.h>

int main() {
    int passwordMatches = 0;
    char userInput[10];
    char correctPassword[] = "secret";

    printf("Enter password: ");
    scanf("%9s", userInput);

    if (userInput = correctPassword) {
        passwordMatches = 1;
    }

    if (passwordMatches) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}