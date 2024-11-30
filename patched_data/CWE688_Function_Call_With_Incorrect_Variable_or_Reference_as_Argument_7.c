#include <stdio.h>

void printValue(int x) {
    printf("Value: %d\n", x);
}

int main() {
    int correctValue = 10;
    printValue(correctValue);
    
    return 0;
}