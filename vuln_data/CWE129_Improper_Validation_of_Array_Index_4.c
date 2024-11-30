#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10];
    char input[10];
    fgets(input, sizeof(input), stdin);
    int index = atoi(input);
    if (index >= 0 && index < 10) {
        printf("Value at index %d is %d\n", index, array[index]);
    } else {
        printf("Index out of bounds\n");
    }
    return 0;
}