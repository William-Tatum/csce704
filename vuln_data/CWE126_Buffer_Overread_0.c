#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10] = "ABCDEFGHI";
    char userInput[20];
    strcpy(userInput, "0123456789EXPLOIT");

    for (int i = 0; i < 20; i++) {
        printf("%c\n", userInput[i]);
    }

    return 0;
}