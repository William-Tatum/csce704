#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10] = {0}; // Initialize array to avoid using uninitialized values
    char input[10];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char *endptr;
        long index = strtol(input, &endptr, 10);
        if (endptr != input && *endptr == '\n' && index >= 0 && index < 10) {
            printf("Value at index %ld is %d\n", index, array[index]);
        } else {
            printf("Index out of bounds or invalid input\n");
        }
    } else {
        printf("Error reading input\n");
    }
    return 0;
}