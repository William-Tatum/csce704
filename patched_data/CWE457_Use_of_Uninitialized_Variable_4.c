#include <stdio.h>

void printValue() {
    int value = 0;  // Initialize variable to prevent usage of uninitialized value
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