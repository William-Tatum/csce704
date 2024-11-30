#include <stdio.h>
#include <string.h>

void printUserInput() {
    char buffer[10];
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  // Removing trailing newline
    for (int i = 0; i < sizeof(buffer) && buffer[i] != '\0'; i++) {
        printf("%c", buffer[i]);
    }
}

int main() {
    printUserInput();
    return 0;
}