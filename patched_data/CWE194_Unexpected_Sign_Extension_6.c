#include <stdio.h>
#include <limits.h>

void processNumber(short input) {
    unsigned long extendedInput;

    if (input < 0) {
        printf("Error: Negative input\n");
        return;
    }

    extendedInput = (unsigned long)input;
    printf("Processed number: %lu\n", extendedInput);
}

int main() {
    short num;
    int result;

    printf("Enter a number: ");
    result = scanf("%hd", &num);

    if (result != 1) {
        printf("Error: Invalid input\n");
        return 1;
    }

    if (num < SHRT_MIN || num > SHRT_MAX) {
        printf("Error: Input out of range\n");
        return 1;
    }

    processNumber(num);

    return 0;
}