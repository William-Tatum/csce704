#include <stdio.h>

void printNumber(char num) {
    printf("Truncated number: %d\n", num);
}

int main() {
    int largeNumber = 300;
    char smallNumber = (char)largeNumber;
    printNumber(smallNumber);
    return 0;
}