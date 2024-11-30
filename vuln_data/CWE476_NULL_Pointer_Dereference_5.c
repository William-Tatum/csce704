#include <stdio.h>

void printNumber(int *ptr) {
    printf("Number: %d\n", *ptr);
}

int main() {
    int *ptr = NULL;
    printNumber(ptr);
    return 0;
}