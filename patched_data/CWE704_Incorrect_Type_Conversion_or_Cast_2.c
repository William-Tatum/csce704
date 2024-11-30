#include <stdio.h>

void calculateDiscount(float *input) {
    float discountRate = *input;
    printf("Discount Rate: %.2f%%\n", discountRate);
}

int main() {
    float userInput = 10.5f;
    calculateDiscount(&userInput);
    return 0;
}