#include <stdio.h>

void checkValue(int value) {
    int min = 0;
    int max = 10;
    if (value >= min && value <= max) {
        printf("Value is within the range.\n");
    } else {
        printf("Value is out of the range.\n");
    }
}

int main() {
    int value;
    printf("Enter a value: ");
    if (scanf("%d", &value) == 1) {
        checkValue(value);
    } else {
        printf("Invalid input.\n");
    }
    return 0;
}