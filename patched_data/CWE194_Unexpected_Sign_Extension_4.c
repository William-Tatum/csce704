#include <stdio.h>

int main() {
    short smallNumber = -10;
    int convertedNumber = (int) smallNumber;
    if (convertedNumber < 0) {
        convertedNumber = 0;
    }
    unsigned int largeNumber = (unsigned int) convertedNumber;
    printf("Resulting number: %u\n", largeNumber);
    return 0;
}