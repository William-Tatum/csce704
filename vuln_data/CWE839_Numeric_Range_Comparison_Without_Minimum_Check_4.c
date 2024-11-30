#include <stdio.h>
#include <stdbool.h>

bool isValidAmount(int value, int min, int max) {
    if (value >= min && value <= max) {
        return true;
    }
    return false;
}

int main() {
    int requestedItems = -3;
    int minItems = 0;
    int maxItems = 10;

    if (isValidAmount(requestedItems, minItems, maxItems)) {
        printf("The requested amount of %d items is valid.\n", requestedItems);
    } else {
        printf("The requested amount of %d items is invalid.\n", requestedItems);
    }

    return 0;
}