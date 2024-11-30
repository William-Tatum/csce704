#include <stdio.h>
#include <stdbool.h>

bool isValidAmount(int value, int min, int max) {
    if (value >= min && value <= max) {
        return true;
    }
    return false;
}

int main() {
    int requestedItems;
    int minItems = 0;
    int maxItems = 10;

    printf("Enter the number of items: ");
    if (scanf("%d", &requestedItems) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isValidAmount(requestedItems, minItems, maxItems)) {
        printf("The requested amount of %d items is valid.\n", requestedItems);
    } else {
        printf("The requested amount of %d items is invalid.\n", requestedItems);
    }

    return 0;
}