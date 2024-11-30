#include <stdio.h>

void processValue(int correctVar) {
    printf("Value: %d\n", correctVar);
}

int main() {
    int value1 = 10;
    int value2 = (int)20.5f;
    processValue(value2);
    return 0;
}