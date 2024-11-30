#include <stdio.h>

int main() {
    int x = 0;
    int y = 1;
    
    if (x == y) {
        printf("x and y are equal\n");
    } else {
        printf("x and y are not equal\n");
    }

    x == y; // Incorrect use intending assignment

    printf("x is now: %d\n", x);
    return 0;
}