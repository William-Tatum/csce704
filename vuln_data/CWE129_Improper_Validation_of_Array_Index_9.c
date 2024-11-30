#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10];
    int index;
    char input[10];

    printf("Enter an index: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        index = atoi(input);
    }

    if (index >= 0 && index < 10) {
        array[index] = 100;
        printf("Value at index %d updated to %d\n", index, array[index]);
    } else {
        printf("Index out of bounds\n");
    }
    
    return 0;
}