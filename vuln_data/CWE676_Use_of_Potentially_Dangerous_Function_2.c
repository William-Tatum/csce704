#include <stdio.h>
#include <string.h>

int main() {
    char buffer[50];
    char input[100];
    printf("Enter your name: ");
    fgets(input, sizeof(input), stdin);
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Hello, %s", buffer);
    return 0;
}