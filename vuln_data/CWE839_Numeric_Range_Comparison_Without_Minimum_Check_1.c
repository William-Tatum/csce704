#include <stdio.h>

#define MAX_ALLOWED 10

int main() {
    int value;

    printf("Enter a value: ");
    scanf("%d", &value);

    if (value >= 0 && value <= MAX_ALLOWED) {
        printf("Valid value: %d\n", value);
    } else {
        printf("Invalid value: %d. Must be between 0 and %d.\n", value, MAX_ALLOWED);
    }

    return 0;
}