#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 64

void secureAddString(char *input) {
    char buffer[MAX_LENGTH];
    if (strlen(input) >= MAX_LENGTH) {
        printf("Error: Input string is too long.\n");
        return;
    }
    strcpy(buffer, input);
    printf("Stored string: %s\n", buffer);
}

int main() {
    char safeString[MAX_LENGTH] = "Hello, World!";
    secureAddString(safeString);
    return 0;
}