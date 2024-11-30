#include <stdio.h>
#include <string.h>

void safeFunction(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char input[50];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    safeFunction(input);
    return 0;
}