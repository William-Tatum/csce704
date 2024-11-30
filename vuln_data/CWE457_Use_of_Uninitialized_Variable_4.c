#include <stdio.h>

void printValue() {
    int value;
    if (value > 0) {
        printf("The value is positive: %d\n", value);
    } else {
        printf("The value is non-positive: %d\n", value);
    }
}

int main() {
    printValue();
    return 0;
}