#include <stdio.h>

int* getNumber() {
    int num = 42;
    return &num;
}

int main() {
    int *ptr = getNumber();
    printf("Value: %d\n", *ptr);
    return 0;
}