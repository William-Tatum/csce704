#include <stdio.h>

void processValue(int correctVar) {
    printf("Value: %d\n", correctVar);
}

int main() {
    int value1 = 10;
    float value2 = 20.5f;
    processValue(value2); // Incorrect variable type passed
    return 0;
}