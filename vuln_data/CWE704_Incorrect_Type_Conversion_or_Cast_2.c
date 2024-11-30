#include <stdio.h>

void calculateDiscount(void *input) {
    int discountRate;
    discountRate = *(int *)input;
    printf("Discount Rate: %d%%\n", discountRate);
}

int main() {
    float userInput = 10.5f;
    calculateDiscount(&userInput);
    return 0;
}