#include <stdio.h>

void inherently_dangerous() {
    char buffer[10];
    printf("Enter some text: ");
    gets(buffer);
    printf("You entered: %s\n", buffer);
}

int main() {
    inherently_dangerous();
    return 0;
}