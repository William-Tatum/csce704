#include <stdio.h>

#define MIN_VALUE 0
#define MAX_VALUE 10

void processInput(int value) {
    if (value >= MIN_VALUE && value <= MAX_VALUE) {
        printf("Processing value: %d\n", value);
    } else {
        printf("Value out of range.\n");
    }
}

int main() {
    int userInput;
    printf("Enter a number between %d and %d: ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &userInput);
    processInput(userInput);
    return 0;
}