#include <stdio.h>
#include <stdlib.h>

void printFormatted(const char *userInput) {
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%s", userInput);
    printf(buffer);
}

int main() {
    char input[100];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        printFormatted(input);
    }
    return 0;
}