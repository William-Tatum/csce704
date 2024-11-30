#include <stdio.h>

int main() {
    char userInput[100];
    printf("Enter a format string: ");
    scanf("%99s", userInput);

    printf(userInput);  // Vulnerable to format string attacks
    return 0;
}