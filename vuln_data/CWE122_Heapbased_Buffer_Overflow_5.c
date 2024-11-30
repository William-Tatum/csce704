#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerableFunction(char *input) {
    char *buffer = (char *)malloc(10);
    if (!buffer) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(buffer, input);
    printf("Buffer contents: %s\n", buffer);
    free(buffer);
}

int main() {
    char largeInput[20];
    strcpy(largeInput, "This is a long input");
    vulnerableFunction(largeInput);
    return 0;
}