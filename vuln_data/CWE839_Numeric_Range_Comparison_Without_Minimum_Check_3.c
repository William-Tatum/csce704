#include <stdio.h>

void processOrder(int items) {
    int minItems = 0;
    int maxItems = 10;

    if (items >= minItems && items <= maxItems) {
        printf("Processing order for %d items.\n", items);
    } else {
        printf("Invalid number of items: %d. Please order between %d and %d items.\n", items, minItems, maxItems);
    }
}

int main() {
    int userItems;
    printf("Enter the number of items you want to order: ");
    scanf("%d", &userItems);
    processOrder(userItems);
    return 0;
}