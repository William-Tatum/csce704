#include <stdio.h>

#define MAX_ALLOWED 10

int main() {
    int value;
    int result;

    printf("Enter a value: ");
    result = scanf("%d", &value);

    if (result != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (value >= 0 && value <= MAX_ALLOWED) {
        printf("Valid value: %d\n", value);
    } else {
        printf("Invalid value: %d. Must be between 0 and %d.\n", value, MAX_ALLOWED);
    }

    return 0;
}