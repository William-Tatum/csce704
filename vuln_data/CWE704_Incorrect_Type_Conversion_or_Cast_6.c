#include <stdio.h>

int main() {
    double large_number = 1.999999;
    int incorrect_cast = (int)large_number;
    printf("Incorrectly casted number: %d\n", incorrect_cast);
    return 0;
}