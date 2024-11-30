#include <stdio.h>

int main() {
    int data;
    int array[10] = {0};
    printf("Enter an index: ");
    if (scanf("%d", &data) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (data >= 0 && data < 10) {
        array[data] = 1;
        printf("Index %d is set to 1\n", data);
    } else {
        printf("Index out of bounds\n");
    }
    return 0;
}