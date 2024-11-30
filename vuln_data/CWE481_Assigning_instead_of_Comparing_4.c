#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    if (a = b) { // Incorrect use of assignment instead of comparison
        printf("The values are equal.\n");
    }

    return 0;
}