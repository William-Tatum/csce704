#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    char userInput[BUFFER_SIZE];
    printf("Enter your input: ");
    fgets(userInput, BUFFER_SIZE, stdin);

    char fixedMessage[50] = "Fixed message: ";
    printf(fixedMessage);
    printf(userInput);

    return 0;
}