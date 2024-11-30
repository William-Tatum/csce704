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
    scanf("%hd", &inputNumber);
    handleData(inputNumber);
    return 0;
}