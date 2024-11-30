#include <stdio.h>

void printNumber(int *ptr) {
    if (ptr != NULL) {
        printf("Number: %d\n", *ptr);
    } else {
        printf("Pointer is NULL\n");
    }
}

int main() {
    int number = 42;
    int *ptr = &number;
    printNumber(ptr);
    return 0;
}