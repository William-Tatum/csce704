#include <stdio.h>
#include <string.h>

void printUserInput() {
    char buffer[10];
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);
    for (int i = 0; i <= 10; i++) {
        printf("%c", buffer[i]);
    }
}

int main() {
    printUserInput();
    return 0;
}