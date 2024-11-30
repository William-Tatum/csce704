#include <stdio.h>

int main() {
    int requested_items;
    const int MAX_ITEMS = 10;
    const int MIN_ITEMS = 0;

    printf("Enter the number of items: ");
    if (scanf("%d", &requested_items) != 1) {
        printf("Error: Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    if (requested_items >= MIN_ITEMS && requested_items <= MAX_ITEMS) {
        printf("Valid number of items requested: %d\n", requested_items);
    } else {
        printf("Error: Number of items requested must be between %d and %d.\n", MIN_ITEMS, MAX_ITEMS);
    }

    return 0;
}