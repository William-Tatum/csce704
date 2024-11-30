#include <stdio.h>

int main() {
    int value;
    int MAX_VALUE = 100;
    int MIN_VALUE = 0;

    printf("Enter a value: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (value >= MIN_VALUE && value <= MAX_VALUE) {
        printf("Value is within the acceptable range.\n");
    } else {
        printf("Value is out of range.\n");
    }

    return 0;
}