#include <stdio.h>

void printSum() {
    int a, b, sum;
    b = 10;
    // 'a' is not initialized
    sum = a + b;
    printf("The sum is: %d\n", sum);
}

int main() {
    printSum();
    return 0;
}