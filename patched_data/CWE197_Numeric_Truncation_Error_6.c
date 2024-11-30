#include <stdio.h>

int main() {
    int largeNumber = 300;
    unsigned char smallNumber;

    if (largeNumber >= 0 && largeNumber <= UCHAR_MAX) {
        smallNumber = (unsigned char)largeNumber;
        printf("Original number: %d\n", largeNumber);
        printf("Converted number: %d\n", smallNumber);
    } else {
        printf("Error: The number %d is out of range for a char.\n", largeNumber);
    }

    return 0;
}