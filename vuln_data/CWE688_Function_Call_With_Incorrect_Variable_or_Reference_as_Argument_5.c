#include <stdio.h>

void updateValue(int *correctVar, int incorrectVar) {
    *correctVar = 50;
}

int main() {
    int correctVar = 10;
    int someOtherVar = 25;
    updateValue(&someOtherVar, correctVar);
    printf("The value is: %d\n", someOtherVar);
    return 0;
}