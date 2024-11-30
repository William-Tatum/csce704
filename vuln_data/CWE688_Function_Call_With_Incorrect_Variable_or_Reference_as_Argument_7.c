#include <stdio.h>

void printValue(int x) {
    printf("Value: %d\n", x);
}

int main() {
    int correctValue = 10;
    char incorrectData = 'A';
    
    printValue(incorrectData);
    
    return 0;
}