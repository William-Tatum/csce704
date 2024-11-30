#include <stdio.h>

int main() {
    int data[5] = {1, 2, 3, 4, 5};
    int *ptr1 = data;
    int *ptr2 = data;

    ptr1 = ptr1 + 1;
    ptr2 = ptr2 + 1;

    printf("ptr1 points to: %d\n", *ptr1);
    printf("ptr2 points to: %d\n", *ptr2);

    return 0;
}