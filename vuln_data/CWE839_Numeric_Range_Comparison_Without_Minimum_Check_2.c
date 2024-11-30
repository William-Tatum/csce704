#include <stdio.h>

int main() {
    int value;
    const int MAX_VALUE = 100;
    const int MIN_VALUE = 0;
    printf("Enter a value between %d and %d: ", MIN_VALUE, MAX_VALUE);
    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (value >= MIN_VALUE && value <= MAX_VALUE) {
        printf("Valid value: %d\n", value);
    } else {
        printf("Error: Value out of range.\n");
    }
    return 0;
}