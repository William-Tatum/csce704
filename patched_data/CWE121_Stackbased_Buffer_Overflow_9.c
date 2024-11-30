#include <stdio.h>
#include <string.h>

void safeFunction(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
}

int main() {
    char largeInput[20] = "This is too long";
    safeFunction(largeInput);
    printf("Processed input\n");
    return 0;
}