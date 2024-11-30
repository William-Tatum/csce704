#include <stdio.h>

int main() {
    char userInput[100];
    printf("Enter a format string: ");
    scanf("%99s", userInput);

    printf("%s", userInput);
    return 0;
}