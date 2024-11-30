#include <stdio.h>

int main() {
    int largeNumber = 300;
    char smallNumber;

    smallNumber = (char)largeNumber;

    printf("Original number: %d\n", largeNumber);
    printf("Truncated number: %d\n", smallNumber);

    return 0;
}