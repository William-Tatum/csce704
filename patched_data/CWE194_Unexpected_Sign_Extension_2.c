#include <stdio.h>
#include <stdint.h>

void handleData(int16_t smallNumber) {
    uint32_t extendedNumber;
    if (smallNumber < 0) {
        printf("Error: Input number should not be negative\n");
        return;
    }
    extendedNumber = (uint32_t)smallNumber;
    printf("Extended number: %u\n", extendedNumber);
}

int main() {
    int16_t inputNumber;
    printf("Enter a number: ");
    if (scanf("%hd", &inputNumber) != 1) {
        printf("Error: Invalid input\n");
        return 1;
    }
    handleData(inputNumber);
    return 0;
}