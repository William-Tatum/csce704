#include <stdio.h>
#include <string.h>

void copyInputToBuffer(char *input) {
    char buffer[10];
    strcpy(buffer, input); // Vulnerable: no size check on input
    printf("Buffer contains: %s\n", buffer);
}

int main() {
    char input[50];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    copyInputToBuffer(input);
    return 0;
}