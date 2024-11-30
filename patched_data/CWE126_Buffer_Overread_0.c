#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10] = "ABCDEFGHI";
    char userInput[20];
    strncpy(userInput, "0123456789EXPLOIT", sizeof(userInput) - 1);
    userInput[sizeof(userInput) - 1] = '\0';

    for (int i = 0; i < sizeof(userInput); i++) {
        printf("%c\n", userInput[i]);
    }

    return 0;
}