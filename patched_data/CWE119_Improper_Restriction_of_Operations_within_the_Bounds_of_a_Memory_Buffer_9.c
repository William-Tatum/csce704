#include <stdio.h>
#include <string.h>

void fixedFunction() {
    char buffer[10];
    char input[100];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("You entered: %s\n", buffer);
}

int main() {
    fixedFunction();
    return 0;
}