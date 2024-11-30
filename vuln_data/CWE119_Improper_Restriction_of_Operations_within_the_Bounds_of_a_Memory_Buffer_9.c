#include <stdio.h>
#include <string.h>

void vulnerableFunction() {
    char buffer[10];
    char input[100];
    printf("Enter some text: ");
    fgets(input, 100, stdin);
    strcpy(buffer, input);
    printf("You entered: %s\n", buffer);
}

int main() {
    vulnerableFunction();
    return 0;
}