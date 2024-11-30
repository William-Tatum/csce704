#include <stdio.h>

int main() {
    int array[10];
    int index;
    printf("Enter an array index: ");
    if (scanf("%d", &index) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (index >= 0 && index < 10) {
        array[index] = 1;
        printf("Array element set successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
    return 0;
}