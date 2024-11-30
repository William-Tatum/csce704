#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char input[50];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    vulnerableFunction(input);
    return 0;
}