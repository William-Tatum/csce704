#include <stdio.h>

int main() {
    int array[10];
    int index;
    printf("Enter an array index: ");
    scanf("%d", &index);
    if (index >= 0 && index < 10) {
        array[index] = 1;
        printf("Array element set successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
    return 0;
}