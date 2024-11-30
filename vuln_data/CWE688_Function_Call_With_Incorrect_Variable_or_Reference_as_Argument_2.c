#include <stdio.h>

void displayValue(int value) {
    printf("Value: %d\n", value);
}

int main() {
    int a = 10;
    float b = 20.5;

    displayValue(b);  // Incorrect variable type is passed

    return 0;
}