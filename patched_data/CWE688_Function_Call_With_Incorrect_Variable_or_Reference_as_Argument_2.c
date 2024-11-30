#include <stdio.h>

void displayValue(float value) {
    printf("Value: %.2f\n", value);
}

int main() {
    int a = 10;
    float b = 20.5;

    displayValue(b);

    return 0;
}