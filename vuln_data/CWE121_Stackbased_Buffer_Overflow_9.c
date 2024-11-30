#include <stdio.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char buffer[10];
    strcpy(buffer, input);
}

int main() {
    char largeInput[20] = "This is too long";
    vulnerableFunction(largeInput);
    printf("Processed input\n");
    return 0;
}