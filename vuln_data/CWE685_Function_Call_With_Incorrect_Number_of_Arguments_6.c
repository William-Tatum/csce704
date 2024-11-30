#include <stdio.h>

void printSum(int a, int b) {
    printf("Sum: %d\n", a + b);
}

int main() {
    int x = 5;
    int y = 10;
    int z = 15;
    printSum(x, y, z); // Incorrect number of arguments
    return 0;
}