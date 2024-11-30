#include <stdio.h>

void printNumber(int num) {
    printf("Number: %d\n", num);
}

int main() {
    float incorrectArgument = 12.34;
    printNumber(incorrectArgument); // CWE-688: Wrong argument type, should be an int
    return 0;
}