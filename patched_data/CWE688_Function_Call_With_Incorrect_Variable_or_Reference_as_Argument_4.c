#include <stdio.h>

void printNumber(int num) {
    printf("Number: %d\n", num);
}

int main() {
    int correctArgument = (int)12.34;
    printNumber(correctArgument);
    return 0;
}