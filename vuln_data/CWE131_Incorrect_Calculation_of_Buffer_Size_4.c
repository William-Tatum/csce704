#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unsafeFunction(char *input) {
    size_t len = strlen(input);
    char *buffer = (char *)malloc(len * sizeof(char));
    strcpy(buffer, input);
    printf("Buffer: %s\n", buffer);
    free(buffer);
}

int main() {
    char userInput[50];
    printf("Enter input: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    unsafeFunction(userInput);
    return 0;
}