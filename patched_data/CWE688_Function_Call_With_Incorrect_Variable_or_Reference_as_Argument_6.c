#include <stdio.h>

void printValue(int value) {
    printf("Value: %d\n", value);
}

int main() {
    int correctValue = 42;
    float incorrectValue = 3.14;
    printValue((int)incorrectValue);  // Cast to int before passing
    return 0;
}