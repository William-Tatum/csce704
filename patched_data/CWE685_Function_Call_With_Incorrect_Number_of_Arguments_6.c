#include <stdio.h>

void printSum(int a, int b) {
    printf("Sum: %d\n", a + b);
}

int main() {
    int x = 5;
    int y = 10;
    printSum(x, y);
    return 0;
}